#include <stdio.h>

#define ALPHABET_SIZE   26

void main(int argc, char **argv){
    if(argc == 2){
        if((argv[1][0] == 'h') | (argv[1][0] == 'v')){
            char c = 0;
            int hist_lengths[ALPHABET_SIZE] = {0};
            int max_hist = 0;
            int index = 0;
            int star_index = 0;

            while((c = getchar()) != EOF){
                if((c >= 'A') & (c <= 'Z'))
                    index = c - 'A';
                else if((c >= 'a') & (c <= 'z'))
                    index = c - 'a';
                hist_lengths[index]++;
                if(hist_lengths[index] > max_hist)
                    max_hist = hist_lengths[index];
            }
            if(argv[1][0] == 'h'){
                for(index = 0; index < ALPHABET_SIZE; index++){
                    printf("%2c: ", index + 'a');
                    for(star_index = 0; star_index < hist_lengths[index]; star_index++)
                        printf("*");
                    printf("\n");
                }
            }
            else if(argv[1][0] == 'v'){
                for(index = 0; index < ALPHABET_SIZE; index++)
                    printf("%2c ", index + 'a');
                printf("\n");
                for(star_index = 0; star_index < max_hist; star_index++){
                    for(index = 0; index < ALPHABET_SIZE; index++){
                        if(hist_lengths[index] <= 0)
                            printf("   ");
                        else{
                            printf(" * ");
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