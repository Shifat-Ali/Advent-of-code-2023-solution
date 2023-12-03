#include <iostream>
#include <vector>
using namespace std;

#define MAXR 12
#define MAXB 14
#define MAXG 13

struct game
{
    int id;
    vector<int> red, blue, green;
    int max_red, max_blue, max_green;
    long long power;
    bool good;
};

void process(vector<string> &v, int &sum, long long &sum2, struct game *obj, FILE *out = nullptr, FILE *out2 = nullptr)
{
    obj->red.clear();
    obj->blue.clear();
    obj->green.clear();
    obj->max_red = 0;
    obj->max_blue = 0;
    obj->max_green = 0;
    obj->power = 0;
    obj->good = true;
    obj->id = -1;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "Game")
        {
            obj->id = stoi(v[i + 1]);
        }
        else if (v[i] == "red")
        {
            obj->red.push_back(stoi(v[i - 1]));
        }
        else if (v[i] == "blue")
        {
            obj->blue.push_back(stoi(v[i - 1]));
        }
        else if (v[i] == "green")
        {
            obj->green.push_back(stoi(v[i - 1]));
        }
    }

    for (auto &x : obj->red)
    {
        obj->max_red = max(obj->max_red, x);
        if (x > MAXR)
        {
            obj->good = false;
        }
    }

    for (auto &x : obj->blue)
    {
        obj->max_blue = max(obj->max_blue, x);
        if (x > MAXB)
        {
            obj->good = false;
        }
    }

    for (auto &x : obj->green)
    {
        obj->max_green = max(obj->max_green, x);
        if (x > MAXG)
        {
            obj->good = false;
        }
    }

    if (obj->good && obj->id != -1)
    {
        sum += obj->id;
        if (out != nullptr)
        {
            fprintf(out, "\nGame %d: Red:", obj->id);
            for (auto &x : obj->red)
                fprintf(out, " %d", x);
            fprintf(out, " Blue:");
            for (auto &x : obj->blue)
                fprintf(out, " %d", x);
            fprintf(out, " Green:");
            for (auto &x : obj->green)
                fprintf(out, " %d", x);
        }
    }

    // for part 2;
    obj->power = (long long)(obj->max_red * obj->max_blue * obj->max_green);
    if (out2 != nullptr && obj->id != -1)
    {
        sum2 += obj->power;
        fprintf(out2, "Game %d: Red -> %d, Blue -> %d, Green -> %d, Power: %ld\n", obj->id, obj->max_red, obj->max_blue, obj->max_green, obj->power);
    }
}

int main()
{
    FILE *file = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    FILE *out2 = fopen("output_2.txt", "w");
    vector<string> v;
    int sum = 0;
    long long sum2 = 0;
    struct game obj;
    fprintf(out, "Valid Games with maximum Red: %d, Blue %d, Green %d", MAXR, MAXB, MAXG);
    // splitting the input;
    char c;
    string s = "";
    while ((c = fgetc(file)))
    {
        if (c == ' ' || c == ':' || c == ';' || c == ',' && !s.empty())
        {
            v.push_back(s);
            s.clear();
        }
        else if (c == '\n' || c == EOF)
        {
            if (!s.empty())
            {
                v.push_back(s);
                s.clear();
            }

            process(v, sum, sum2, &obj, out, out2);

            v.clear();
        }
        else
        {
            s.push_back(c);
        }

        if (c == EOF)
            break;
    }

    fprintf(out, "\nAnswer: %d", sum);
    fprintf(out2, "Answer: %ld", sum2);

    fclose(file);
    fclose(out);
    fclose(out2);
}