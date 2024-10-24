#include<stdio.h>
#include<stdlib.h>

 int main()
{
    int m[1000],n[1000], p[2000], j;
    int count = 0, count2 = 0;
    char input[1000], input2[1000];
    int total_count = 0, final_count = 0;
    int finais[1000];
    float mediana;


    printf("entrada:\n");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++)
    {
        int num = 0;
        while (input[i] >= '0' && input[i] <= '9')
         {
            num = num * 10 + (input[i] - '0');
            i++;
        }
        if (i > 0 && input[i - 1] >= '0' && input[i - 1] <= '9')
        {
            m[count] = num;
            count++;
        }
    }

    fgets(input2, sizeof(input2), stdin);
    for (int i = 0; input2[i] != '\0'; i++)
    {
        int num = 0;
        while (input2[i] >= '0' && input2[i] <= '9')
        {
            num = num * 10 + (input2[i] - '0');
            i++;
        }

        if (i > 0 && input2[i - 1] >= '0' && input2[i - 1] <= '9')
        {
            n[count2] = num;
            count2++;
        }
    }



    for (int i = 0; i < count; i++)
    {
        p[total_count++] = m[i];
    }
    for (int i = 0; i < count2; i++)
    {
        p[total_count++] = n[i];
    }
    for (int i = 0; i < total_count - 1; i++)
    {
        for (int j = 0; j < total_count - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < total_count; i++) {
        if (i == 0 || p[i] != p[i - 1]) {
            finais[final_count++] = p[i];
        }
    }
    printf("Saidas: \n");

    if (final_count > 0) {
        if (final_count % 2 == 0) {
            mediana = (finais[final_count / 2 - 1] + finais[final_count / 2])/2;
        }
        else {
            mediana = finais[final_count/2]+0,5;
        }
        printf("%.1f\n", mediana);
    }

    printf("[");
    for (int j = 0; j < final_count; j++) {
        printf("%d", finais[j]);
        if(j < final_count-1 ){
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
