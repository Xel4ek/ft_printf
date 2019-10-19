#include "ft_printf.h"

int shift_string(char *str, int max_len) {
    int j;
    int count;

    j = 0;
    count = -3;
    while (j < max_len) {
        if (str[j++] != 0)
            break;
        count++;
    }
    if (j == max_len)
		return 0;
    if (count > 0) {
        j = 0;
        while (j++ < max_len - count)
            str[j] = str[j + count];
        while (j < max_len + 1)
            str[j++] = 0;
    } else if (count < 0) {
        j = max_len;
        while (j-- > -count)
            str[j] = str[j + count];
        while (j--)
            str[j] = 0;
    }
    return count;
}

void division_two_e(char *str, int max_len) {
    int j;

    j = max_len;
    while (j--) {
        str[j + 1] += (str[j] % 2) * 5;
        str[j] /= 2;
        if (str[j + 1] > 9) {
            str[j + 1] %= 10;
            str[j]++;
        }
    }
}

void add_exponent(t_param *param, int power) {
    char prefix[] = {'e', 0, 0, 0};
    char *temp;
    char *temp2;
    char *temp3;

    if (power >= 0)
        prefix[1] = '+';
    else
        prefix[1] = '-';
    if (abs(power) < 10)
        prefix[2] = '0';
    temp3 = ft_itoa(abs(power));
    temp = ft_strjoin(prefix, temp3);
    temp2 = ft_strjoin(param->str, temp);
    ft_memdel((void **) &temp3);
    ft_memdel((void **) &param->str);
    ft_memdel((void **) &temp);
    param->str = temp2;
    param->line_size = ft_strlen(param->str);
}

void multiply_two(char *str, int max_len) {
    int in_main;
    int j;

    j = max_len;
    in_main = 0;
    while (j-- > 0) {
        str[j] = 2 * str[j] + in_main;
        in_main = str[j] / 10;
        str[j] %= 10;
    }
}
void division_two(char *str, int max_len, int i) {
    int j;

    j = max_len;
    while (j--) {
        str[j + 1] += (str[j] % 2) * 5;
        str[j] /= 2;
        if (str[j + 1] > 9) {
            str[j + 1] %= 10;
            str[j] += 1;
        }
        if (i == 0 && j == max_len - 2)
            if (str[j + 1] > 5)
                str[j]++;
    }
}