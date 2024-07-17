#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_SOUNDEX_CODE_LENGTH 4
#define SOUNDEX_CODE_SIZE (MAX_SOUNDEX_CODE_LENGTH + 1)
 
static const char soundex_map[] = {
    'b', 'f', 'p', 'v', // b, f, p, v
    'c', 'g', 'j', 'k', 'q', 's', 'x', 'z', // c, g, j, k, q, s, x, z
    'd', 't', // d, t
    'l', // l
    'm', 'n', // m, n
    'r', // r
};
 
static char soundex_code(char c) {
    c = tolower(c);
    const char* p = strchr(soundex_map, c);
    return p ? '1' + (p - soundex_map) / 7 : '0';
}
 
char* soundex(const char* str) {
    static char soundex_code[SOUNDEX_CODE_SIZE];
    int len = strlen(str);
    int code_idx = 0;
 
    soundex_code[code_idx++] = toupper(str[0]);
 
    for (int i = 1; i < len; i++) {
        char c = tolower(str[i]);
        const char* p = strchr(soundex_map, c);
        char code = p ? '1' + (p - soundex_map) / 7 : '0';
 
        if (code != '0' && code != soundex_code[code_idx - 1]) {
            soundex_code[code_idx++] = code;
        }
    }
 
    while (code_idx < MAX_SOUNDEX_CODE_LENGTH) {
        soundex_code[code_idx++] = '0';
    }
 
    soundex_code[code_idx] = '\0'; // null-terminate
    return soundex_code;
}
 
#endif // SOUNDEX_H
