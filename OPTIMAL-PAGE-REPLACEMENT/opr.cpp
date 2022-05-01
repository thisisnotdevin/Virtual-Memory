#include <stdio.h>
#include <fstream>
#include <iostream>
// goal: optimal page replacement is to replace the page that we wont be using for a while
using namespace std;
int main()
{
    int frames[10], pages[100], temp[10], flag1, flag2, flag3, i, j, k, pos, avail, max, faults = 0;
    int no_of_frames = 10;
    int no_of_pages = 100;

    ifstream in_stream;
    in_stream.open("data.csv");

    int line;
    int num = 0;              // where each line of the file will go to
    while (in_stream >> line) // read until the end
    {
        pages[num] = line;
        num++;
    }

    for (i = 0; i < no_of_frames; ++i)
    { // initialize the frames to -1
        frames[i] = -1;
    }
    printf("\nREF STORING  \t\t\t PAGE FRAMES     \t\t\tHIT/FAULT\n");
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;

                    break;
                }
            }
        }

        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;

                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;

                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");
        cout << "\t" << pages[i] << "\t\t";

        for (k = 0; k < 10; k++)
        {
            avail = 0;
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;

                for (k = 0; k < 10; k++)
                {
                    printf("%d\t", frames[k]);
                }
                cout << "\tF";
                break;
            }

            if (avail == 0)
            {
                for (k = 0; k < 10; k++)
                    printf("%d\t", frames[k]);
                cout << "\tH";
            }
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}