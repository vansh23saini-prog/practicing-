int romanToInt(char * s) {
    int roman_map[256] = {0};
    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;
    
    int total = 0;
    int prev_value = 0;
    int len = strlen(s);
    
    for (int i = len - 1; i >= 0; i--) {
        int value = roman_map[(unsigned char)s[i]];
        if (value >= prev_value) {
            total += value;
        } else {
            total -= value;
        }
        prev_value = value;
    }
    return total;
}
