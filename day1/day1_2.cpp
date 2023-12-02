#include <iostream>
using namespace std;

// one
// two i += 1
// six i += 2
// four
// five i += 2
// nine i += 1
// three i += 2
// seven
// eight i += 3

bool one(string s, int i, int l)
{
    return ((l - i >= 3) && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e');
}

bool two(string s, int i, int l)
{
    return ((l - i >= 3) && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o');
}

bool three(string s, int i, int l)
{
    return ((l - i >= 5) && s[i] == 't' && s[i + 1] == 'h' && s[i + 2] == 'r' && s[i + 3] == 'e' && s[i + 4] == 'e');
}

bool four(string s, int i, int l)
{
    return ((l - i >= 4) && s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r');
}

bool five(string s, int i, int l)
{
    return ((l - i >= 4) && s[i] == 'f' && s[i + 1] == 'i' && s[i + 2] == 'v' && s[i + 3] == 'e');
}

bool six(string s, int i, int l)
{
    return ((l - i >= 3) && s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'x');
}

bool seven(string s, int i, int l)
{
    return ((l - i >= 5) && s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'v' && s[i + 3] == 'e' && s[i + 4] == 'n');
}

bool eight(string s, int i, int l)
{
    return ((l - i >= 5) && s[i] == 'e' && s[i + 1] == 'i' && s[i + 2] == 'g' && s[i + 3] == 'h' && s[i + 4] == 't');
}

bool nine(string s, int i, int l)
{
    return ((l - i >= 4) && s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'e');
}

void process(string s, int &first, int &last)
{
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0)
        {
            if (first == -1)
                first = s[i] - '0';
            else
                last = s[i] - '0';
        }
        else if (one(s, i, l))
        {
            if (first == -1)
                first = 1;
            else
                last = 1;
        }
        else if (two(s, i, l))
        {
            i += 1;
            if (first == -1)
                first = 2;
            else
                last = 2;
        }
        else if (three(s, i, l))
        {
            i += 2;
            if (first == -1)
                first = 3;
            else
                last = 3;
        }
        else if (four(s, i, l))
        {
            if (first == -1)
                first = 4;
            else
                last = 4;
        }
        else if (five(s, i, l))
        {
            i += 2;
            if (first == -1)
                first = 5;
            else
                last = 5;
        }
        else if (six(s, i, l))
        {
            i += 2;
            if (first == -1)
                first = 6;
            else
                last = 6;
        }
        else if (seven(s, i, l))
        {
            if (first == -1)
                first = 7;
            else
                last = 7;
        }
        else if (eight(s, i, l))
        {
            i += 3;
            if (first == -1)
                first = 8;
            else
                last = 8;
        }
        else if (nine(s, i, l))
        {
            i += 1;
            if (first == -1)
                first = 9;
            else
                last = 9;
        }
    }
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    FILE *out = fopen("output_2.txt", "w");
    int sum = 0;
    string s = "";
    char c;
    int first, last;
    first = last = -1;
    int count = 0;
    while ((c = fgetc(file)) != EOF)
    {
        s.push_back(c);
        if (c == '\n')
        {
            process(s, first, last);
            s = "";
            count++;
            last = last == -1 ? first : last;
            fprintf(out, "%d. first: %d, last: %d -> %d\n", count, first, last, (first * 10 + last));
            sum += (long long)(first * 10 + last);
            first = last = -1;
        }
    }
    process(s, first, last);
    s = "";
    count++;
    last = last == -1 ? first : last;
    fprintf(out, "%d. first: %d, last: %d -> %d\n", count, first, last, (first * 10 + last));
    sum += (long long)(first * 10 + last);
    first = last = -1;
    fprintf(out, "Total SUm: %ld\n", sum);
    fclose(file);
    fclose(out);
}