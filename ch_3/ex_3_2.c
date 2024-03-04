#include <stdio.h>

void escape(char *s, const char *t);
void unescape(char *s, const char *t);

void main(){
    char original[] = "Hello\nWorld\t!";
    char escaped[100];
    char unescaped[100];

    escape(escaped, original);
    unescape(unescaped, escaped);

    printf("Original: %s\n", original);
    printf("Escaped: %s\n", escaped);
    printf("Unescaped: %s\n", unescaped);
}


void escape(char *s, const char *t){
    int i, j;
    for(i = j = 0; t[i] != '\0'; i++, j++){
        switch (t[i]){
            case '\n':
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char *s, const char *t){
    int i, j;
    for(i = j = 0; t[i] != '\0'; i++, j++){
        switch (t[i]){
            case '\\':
                i++;
                if(t[i] == 'n')
                    s[j] = '\n';
                else if(t[i] == 't')
                    s[j] = '\t';
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
    s[j] = '\0';
}