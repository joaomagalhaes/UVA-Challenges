
/*  UVA - The 3n + 1 problem
    Joao David Magalhaes 11/03/14 */

#include <stdio.h>

int results[1000001];
int cycle_len;

void calc(int var)
{
    cycle_len++;
    
    if(var != 1)
    {
        var = var % 2 != 0 ? 3 * var + 1 : var / 2;
        calc(var);
    }
}

int main(int argc, const char * argv[])
{
    int l, i, j, aux, max;
    
    while(scanf("%d %d", &i, &j) != EOF)
    {
        l = 0; if(i > j) { l = i; i = j; j = l; } /* indexes change */
        
        max = 0;
        
        for(aux = i; aux <= j; aux++)
        {
            if(results[aux] == 0) /* if max cycle length for that index isnt already calculated */
            {
                cycle_len = 0;
                calc(aux);
                max = cycle_len > max ? cycle_len : max;
                results[aux] = cycle_len;
            }
            else
                max = results[aux] > max ? results[aux] : max;
        }
        
        l == 0 ? printf("%d %d %d\n", i, j, max) : printf("%d %d %d\n", j, i, max);
    }
    return 0;
}

