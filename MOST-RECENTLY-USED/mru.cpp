#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;
int main()
{

        int i, j, ref_str[100], frame[10], k, avail, fcount = 0; // Declaration of variable required
        int n = 100;                                             // total no. of pages in reference string
        int no = 10;

        ifstream in_stream;
        in_stream.open("data.csv");

        int line;
        int num = 0;              // where each line of the file will go to
        while (in_stream >> line) // read until the end
        {
                ref_str[num] = line;
                num++;
        }

        for (i = 0; i < 10; i++)
        {
                frame[i] = -1; // initialize all page frame to -1
        }
        j = 0; // initialize page frame pointer
        printf("\nREF STORING  \t\t\t PAGE FRAMES     \t\t\tHIT/FAULT\n");
        for (i = 0; i <= n; i++)
        {
                printf("%d\t\t", ref_str[i]);
                avail = 0; // Default value of available flag is 0
                int last;
                for (k = 0; k < 10; k++)

                        if (frame[k] == ref_str[i]) // input of  page  requested is compared with existing content of FRAME // ERROR; no scanning the same frame !!!
                        {
                                last = k;  // set last to k if it hits
                                avail = 1; // as page found available is turned 1
                                for (k = 0; k < 10; k++)
                                {
                                        printf("%d\t", frame[k]); // Print Current state of FRAME
                                }

                                cout << "\tH"; // Indication of Page Hit
                        }
                if (avail == 0) // input page  requested NOT existing in  FRAME
                {

                        if (frame[j] == -1)
                        { // fill the frames until there is no more empty spots
                                frame[j] = ref_str[i];
                                j = (j + 1) % 10;
                                last = 9;
                                fcount++;
                                for (k = 0; k < 10; k++)
                                        printf("%d\t", frame[k]);
                                cout << "\tF";
                        }

                        else if (frame[j] != -1)
                        { // replace the last frame
                                frame[last] = ref_str[i];

                                fcount++;
                                for (k = 0; k < 10; k++)
                                        printf("%d\t", frame[k]);
                                cout << "\tF";
                        }
                }
                printf("\n");
        }
        printf("Page Fault Is %d", fcount);
        return 0;
}
