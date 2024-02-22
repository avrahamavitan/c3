#include <stdlib.h>
#include <stdio.h>
#include "Strlist.h"

#define MAX_LENGTH 100

int main() {
    StrList* str = StrList_alloc();
    int num = 0;

    while (1) {
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        switch (num) {
            case 1: {
                int num_strings;
                scanf("%d", &num_strings);

                for (int i = 0; i < num_strings; ++i) {
                    char str_input[MAX_LENGTH];
                    scanf("%s", str_input);
                    StrList_insertLast(str, str_input);
                }
                break;
            }
            case 2: {
                int x;
                scanf("%d", &x);
                char ch[MAX_LENGTH];
                scanf("%s", ch);
                StrList_insertAt(str, ch, x);
                break;
            }
            case 3:
                StrList_print(str);
                break;
            case 4: {
                int x = StrList_size(str);
                printf("%d\n", x);
                break;
            }
            case 5: {
                int x;
                scanf("%d", &x);
                StrList_printAt(str, x);
                break;
            }
            case 6: {
                int x = StrList_printLen(str);
                printf("%d\n", x);
                break;
            }
            case 7: {
                char ch[MAX_LENGTH];
                scanf("%s", ch);
                int x = StrList_count(str, ch);
                printf("%d\n", x);
                break;
            }
            case 8: {
                char ch[MAX_LENGTH];
                scanf("%s", ch);
                StrList_remove(str, ch);
                break;
            }
            case 9: {
                int x;
                scanf("%d", &x);
                StrList_removeAt(str, x);
                break;
            }
            case 10:
                StrList_reverse(str);
                break;
            case 11:
                StrList_free(str);
                break;
            case 12:
                StrList_sort(str);
                break;
            case 13: {
                int sorted = StrList_isSorted(str);
                if(sorted==1){printf("true\n");}
                else printf("false\n");
            }
            default:
                
                break;
        }
    }

    return 0;
}
