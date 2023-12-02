#include <stdio.h>
using namespace std;

int main()
{
    FILE *file = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    long long sum = 0;
    char c;
    int first, last;
    first = last = -1;
    int count = 0;
    while ((c = fgetc(file)) != EOF)
    {
        if (c - '0' <= 9 && c - '0' >= 0)
        {
            if (first == -1)
                first = c - '0';
            else
                last = c - '0';
        }
        else if (c == '\n')
        {
            count++;
            last = last == -1 ? first : last;
            fprintf(out, "%d. first: %d, last: %d -> %d\n", count, first, last, (first * 10 + last));
            sum += (long long)(first * 10 + last);
            first = last = -1;
        }
    }
    count++;
    last = last == -1 ? first : last;
    fprintf(out, "%d. first: %d, last: %d -> %d\n", count, first, last, (first * 10 + last));
    sum += (long long)(first * 10 + last);
    first = last = -1;
    fprintf(out, "Total SUm: %ld\n", sum);
    fclose(file);
    fclose(out);
}