
#include "cjsonik.h"


stan* stan_gry(const char * const swiat)
{
    stan* gra;
    gra=(stan*) malloc(sizeof(stan));
    const cJSON *payload = NULL;
    const cJSON *status = NULL;
    //int status = 0;
    cJSON *swiat_json = cJSON_Parse(swiat);
    if (swiat_json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        status = 0;
    }

    status = cJSON_GetObjectItemCaseSensitive(swiat_json, "status");
    if (cJSON_IsString(status) && (status->valuestring == "Success"))
    {
        printf("Generowanie świata \"%s\"\n", status->valuestring);
    }

    payload = cJSON_GetObjectItemCaseSensitive(swiat_json, "payload");
    cJSON*name=cJSON_GetObjectItemCaseSensitive(payload, "name");
    cJSON*current_x=cJSON_GetObjectItemCaseSensitive(payload, "current_x");
    cJSON*current_y=cJSON_GetObjectItemCaseSensitive(payload, "current_y");
    cJSON*current_session=cJSON_GetObjectItemCaseSensitive(payload, "current_session");
    cJSON*direction=cJSON_GetObjectItemCaseSensitive(payload, "direction");
    cJSON*step=cJSON_GetObjectItemCaseSensitive(payload, "step");
    cJSON*field_type=cJSON_GetObjectItemCaseSensitive(payload, "field_type");
    cJSON*field_bonus=cJSON_GetObjectItemCaseSensitive(payload, "field_bonus");
    
    gra->direction=(char*) malloc(sizeof(char)*strlen(direction->valuestring)+1);
    gra->field_type=(char*) malloc(sizeof(char)*strlen(field_type->valuestring)+1);
    gra->current_session=(char*) malloc(sizeof(char)*strlen(current_session->valuestring)+1);
    gra->field_bonus=(char*) malloc(sizeof(char)*strlen(field_bonus->valuestring)+1);
    

    gra->name=name->valuestring;
    gra->current_x=current_x->valueint;
    gra->current_y=current_y->valueint;
    strcpy(gra->current_session,current_session->valuestring);
    strcpy(gra->direction,direction->valuestring);
    gra->step=step->valueint;
    strcpy(gra->field_type,field_type->valuestring);
    strcpy(gra->field_bonus,field_bonus->valuestring);


  cJSON_Delete(swiat_json);
  return gra;

}

stanex* stan_gry_ex(const char * const swiat)
{
    stanex* gra;
    int i=0;
    gra=(stanex*) malloc(sizeof(stanex));
    const cJSON *element= NULL;
    const cJSON *payload = NULL;
    const cJSON *list = NULL;
    const cJSON *status = NULL;
    
     
    
    cJSON *swiat_json = cJSON_Parse(swiat);
    if (swiat_json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        status = 0;
    }

    status = cJSON_GetObjectItemCaseSensitive(swiat_json, "status");
    if (cJSON_IsString(status) && (status->valuestring == "Success"))
    {
        printf("Generowanie świata \"%s\"\n", status->valuestring);
    }

    payload = cJSON_GetObjectItemCaseSensitive(swiat_json, "payload");
    list= cJSON_GetObjectItemCaseSensitive(payload, "list");
    cJSON_ArrayForEach(element, list)
    {
        cJSON *x = cJSON_GetObjectItemCaseSensitive(element, "x");
        cJSON *y = cJSON_GetObjectItemCaseSensitive(element, "y");
        cJSON *type = cJSON_GetObjectItemCaseSensitive(element, "type");

        if (!cJSON_IsNumber(x) || !cJSON_IsNumber(y))
        {
            printf("Wczytana dana to nie liczba!");
        }

        gra->x[i]=x->valueint;
        gra->y[i]=y->valueint;
        gra->type[i] = (char*) malloc(sizeof(char) * (strlen(type->valuestring))+1);
        strcpy(gra->type[i], type->valuestring);
        i++; 
    }
    
        
    
    
  cJSON_Delete(swiat_json);
  return gra;

}

void zwolnij_stan(stan* x)
{
    free(x->current_session);
    free(x->direction);
    free(x->field_bonus);
    free(x->field_type);
    free(x);
}

void zwolnij_stan_ex(stanex* x)
{
    for(int i=0;i<3;i++)
    {
        free(x->type[i]);
    }
    free(x);
}