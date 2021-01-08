
#include "cjsonik.h"


plansza stan_gry(const char * const swiat)
{
    plansza super;
    const cJSON *payload = NULL;
    const cJSON *payloads = NULL;
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
       // status = 0;
       // goto end;
    }

    status = cJSON_GetObjectItemCaseSensitive(swiat_json, "status");
    if (cJSON_IsString(status) && (status->valuestring == "Success"))
    {
        printf("Generowanie świata \"%s\"\n", status->valuestring);
    }

    payload = cJSON_GetObjectItemCaseSensitive(swiat_json, "payload");
  //  cJSON_ArrayForEach(resolution, resolutions)
  //  {
  //      cJSON *width = cJSON_GetObjectItemCaseSensitive(payload, "width");
  //      cJSON *height = cJSON_GetObjectItemCaseSensitive(payload, "height");
  //
  //      if (!cJSON_IsNumber(width) || !cJSON_IsNumber(height))
  //      {
  //          status = 0;
  //          goto end;
  //      }
  //
  //      if ((width->valuedouble == 1920) && (height->valuedouble == 1080))
  //      {
  //          status = 1;
  //          goto end;
  //      }
  //  }
    cJSON*current_x=cJSON_GetObjectItemCaseSensitive(payload, "current_x");
    cJSON*current_y=cJSON_GetObjectItemCaseSensitive(payload, "current_y");
    cJSON*current_session=cJSON_GetObjectItemCaseSensitive(payload, "current_session");
    cJSON*direction=cJSON_GetObjectItemCaseSensitive(payload, "direction");
    cJSON*step=cJSON_GetObjectItemCaseSensitive(payload, "step");
    cJSON*field_type=cJSON_GetObjectItemCaseSensitive(payload, "field_type");
    cJSON*field_bonus=cJSON_GetObjectItemCaseSensitive(payload, "field_bonus");

    //printf("%s",field_type->valuestring);
    if(strcmp(field_type->valuestring,"grass")==0)
    printf("kirwa");
    super.tab[current_y->valueint][current_x->valueint]='g';
    if(field_type->valuestring=="sand")
    super.tab[current_y->valueint][current_x->valueint]='s';
    if(field_type->valuestring=="wall")
    super.tab[current_y->valueint][current_x->valueint]='w';

 return super;

 //end:
 //   cJSON_Delete(swiat_json);
 //   return status;
}

void wypisz_macierz(plansza xd)
{
    
    int i, j;
    printf("[ ");
    for (i = 0; i < 10; i++)
    {
        for (j=0; j < 10; j++) 
        {
        printf("%c ", xd.tab[i][j]);
        }
        if (i < (9))
        printf("\n  ");
    }
    printf("]\n");


}

