
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
    
    gra->direction=(char*) malloc(sizeof(char)*strlen(direction->valuestring+1)+10);
    gra->field_type=(char*) malloc(sizeof(char)*strlen(field_type->valuestring+1)+10);
    gra->current_session=(char*) malloc(sizeof(char)*strlen(current_session->valuestring+1)+10);
    gra->field_bonus=(char*) malloc(sizeof(char)*strlen(field_bonus->valuestring+1)+10);
    

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
    int k=1;
    gra=(stanex*) malloc(sizeof(stanex));
    gra->type1=(char*) malloc(sizeof(char)+20);
    gra->type2=(char*) malloc(sizeof(char)+20);
    gra->type3=(char*) malloc(sizeof(char)+20);
    const cJSON *element= NULL;
    const cJSON *payload = NULL;
    const cJSON *list = NULL;
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
    list= cJSON_GetObjectItemCaseSensitive(payload, "list");
    cJSON_ArrayForEach(element, list)
    {
        
        //gra->x = (int*) malloc(sizeof(int));
        //gra->y = (int*) malloc(sizeof(int));
        
        if(k==1)
        {
            cJSON *x1=cJSON_GetObjectItemCaseSensitive(element, "x");
            cJSON *y1=cJSON_GetObjectItemCaseSensitive(element, "y");
            cJSON *type1=cJSON_GetObjectItemCaseSensitive(element, "type");
            gra->x1=x1->valueint;
            gra->y1=y1->valueint;
            strcpy(gra->type1,type1->valuestring);
        }
        if(k==2)
        {
            cJSON*x2=cJSON_GetObjectItemCaseSensitive(element, "x");
            cJSON*y2=cJSON_GetObjectItemCaseSensitive(element, "y");
            cJSON *type2=cJSON_GetObjectItemCaseSensitive(element, "type");
            gra->x2=x2->valueint;
            gra->y2=y2->valueint;
            strcpy(gra->type2,type2->valuestring);
        }
        if(k==3)
        {
            cJSON*x3=cJSON_GetObjectItemCaseSensitive(element, "x");
            cJSON*y3=cJSON_GetObjectItemCaseSensitive(element, "y");
            cJSON *type3=cJSON_GetObjectItemCaseSensitive(element, "type");
            gra->x3=x3->valueint;
            gra->y3=y3->valueint;
            strcpy(gra->type3,type3->valuestring);
        }
   //     cJSON *x=cJSON_GetObjectItemCaseSensitive(element, "x");
   //     cJSON *y=cJSON_GetObjectItemCaseSensitive(element, "y");
   //     cJSON *type=cJSON_GetObjectItemCaseSensitive(element, "type");
  ////    gra->type[k]*=(char**) malloc(sizeof(char*)*strlen(type->valuestring+1));
  //    gra->type = (char**) malloc(sizeof(char*) );
  //    for (i=0;i<m->wiersze;i++) {
  //    m->tab[i] = (float*) malloc(sizeof(float) * m->kolumny);
  //for (j=0;j< m->kolumny; j++)
  //    m->tab[i][j] = j+1+i;

  //
  //    gra->x[k]=x->valueint;
  //    gra->y[k]=y->valueint;
  //      strcpy(gra->type[k]*,type->valuestring);  
        k++;
        
    }
    
  cJSON_Delete(swiat_json);
  return gra;

}

//void wypisz_macierz(plansza xd)
//{
//    
//    int i, j;
//    printf("[ ");
//    for (i = 10; i >0; i--)
//    {
//        for (j=0; j < 10; j++) 
//        {
//        printf("%c ", xd.tab[i][j]);
//        }
//        if (i < (9))
//        printf("\n  ");
//    }
//    printf("]\n");
//
//
//}

