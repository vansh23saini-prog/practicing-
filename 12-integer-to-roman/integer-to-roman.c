char* intToRoman(int num) {
    // List of Roman symbols and their values
    int values[] =    {1000, 900, 500, 400, 100,  90,  50,  40, 10,   9,   5,   4,   1};
    char* symbols[] = {"M",  "CM","D", "CD", "C","XC", "L","XL","X","IX","V","IV","I"};
    static char roman[20]; // Enough for max input, e.g. "MMMCMXCIX"
    int i = 0, pos = 0;

    roman[0] = '\0'; // null-terminated string

    for (i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            // Copy the symbol(s) to result
            for (char* s = symbols[i]; *s; s++) {
                roman[pos++] = *s;
            }
        }
    }
    roman[pos] = '\0';
    return roman;
}
