#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
int main()
{
        int nopages = 100, page[100], i, count = 0;
        const int nofaults = 10;

        ifstream in_stream;
        in_stream.open("data.csv");

        int line;
        int num = 0;              // where each line of the file will go to
        while (in_stream >> line) // read until the end
        {
                page[num] = line;
                num++;
        }

        int frame[nofaults], fcount[nofaults];
        printf("\nREF STORING  \t\t\t PAGE FRAMES     \t\t\tHIT/FAULT\n");
        for (i = 0; i < nofaults; i++)
        {
                frame[i] = -1;
                fcount[i] = 0; // it will keep the track of when the page was last used
        }
        i = 0;
        while (i < nopages)
        {
                int j = 0, flag = 0;
                while (j < nofaults)
                {
                        if (page[i] == frame[j])
                        { // it will check whether the page already exist in frames or not
                                flag = 1;
                                fcount[j] = i + 1;
                        }
                        j++;
                }
                j = 0;
                cout << "\n";
                cout << "\t" << page[i] << "\t\t";
                for (int k = 0; k < 10; k++)
                {
                        if (frame[k] == page[i]) // input of  page  requested is compared with existing content of FRAME
                        {
                                for (j = 0; j < 10; j++)
                                {

                                        cout << " " << frame[j] << " ";
                                }
                                cout << "\tH";
                        }
                }
                if (flag == 0)
                {
                        int min = 0, k = 0;
                        while (k < nofaults - 1)
                        {
                                if (fcount[min] > fcount[k + 1]) // It will calculate the page which is least recently used
                                        min = k + 1;
                                k++;
                        }
                        frame[min] = page[i];
                        fcount[min] = i + 1; // Increasing the time
                        count++;             // it will count the total Page Fault
                        while (j < nofaults)
                        {
                                cout << " " << frame[j] << " ";
                                j++;
                        }
                        cout << "\tF";
                }
                i++;
        }
        cout << "\t \n";
        cout << "\t Page Fault :" << count;
        return 0;
}