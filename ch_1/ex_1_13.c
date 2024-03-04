#include <stdio.h>

#define MAX_WORD_LENGTH 11
#define IN              0
#define OUT             1

void main(int argc, char **argv){
    if(argc == 2){
        if((argv[1][0] == 'h') | (argv[1][0] == 'v')){
            char c = 0;
            int hist_lengths[MAX_WORD_LENGTH] = {0};
            int max_hist = 0;
            int state = OUT;
            int word_len = 0;
            int index = 0;
            int star_index = 0;

            while((c = getchar()) != EOF){
                if((c == ' ') | (c == '\t') | (c == '\n')){
                    state = OUT;
                    if(word_len >= MAX_WORD_LENGTH)
                        hist_lengths[MAX_WORD_LENGTH - 1]++;
                    else
                        hist_lengths[word_len - 1]++;
                    if(word_len > max_hist)
                        max_hist = word_len; 
                    word_len = 0;
                }
                else if(state == OUT){
                    state = IN;
                    word_len++;
                }
                else{
                    word_len++;
                }
            }
            if(argv[1][0] == 'h'){
                for(index = 0; index < MAX_WORD_LENGTH; index++){
                    printf("%2d: ", index + 1);
                    for(star_index = 0; star_index < hist_lengths[index]; star_index++)
                        printf("*");
                    printf("\n");
                }
            }
            else if(argv[1][0] == 'v'){
                for(index = 0; index < MAX_WORD_LENGTH; index++)
                    printf("%2d\t", index + 1);
                printf("\n");
                for(star_index = 0; star_index < max_hist; star_index++){
                    for(index = 0; index < MAX_WORD_LENGTH; index++){
                        if(hist_lengths[index] <= 0)
                            printf("  \t");
                        else{
                            printf(" *\t");
                            hist_lengths[index]--;
                        }
                    }
                    printf("\n");
                }
            }
        } 
        else
            printf("Usage: ./ex <h or v>\n%s\t%s\n", argv[0], argv[1]);
    }
    else
        printf("Usage: ./ex <h or v>\n");
}