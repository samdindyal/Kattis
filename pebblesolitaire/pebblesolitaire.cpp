#include <iostream>
#include <string>
#include <map>

using namespace std;
 
int pebbles;
map <string, int> m;
 
int solve(string line, int pebble_count)
{
    if (m[line] || (pebbles = min(pebbles, pebble_count)) <= 1)
        return m[line];
    string str = line;

    if (line.find("oo-") != string::npos || line.find("-oo") != string::npos)
    {
        for (int i = 1; i < line.length()-1; i++) {
                if (line.at(i) == 'o')
                {
                    if (line.at(i-1) == 'o' && line.at(i+1) == '-')
                    {
                        str.at(i-1) = '-';
                        str.at(i) = '-';
                        str.at(i+1) = 'o';
                        m[str] = solve(str, pebble_count - 1);
                        str = line;
                    }
                    else if (line.at(i-1) == '-' && line.at(i+1) == 'o')
                    {
                        str.at(i-1) = 'o';
                        str.at(i) = '-';
                        str.at(i+1) = '-';
                        m[str] = solve(str, pebble_count - 1);
                        str = line;
                    }
                }
            }
        }
 
    return pebbles;
}
 
int main ()
{
    int n;
    scanf ("%d", &n);
 
    while (n--) {
        string line;
        cin >> line;
        m.clear();
        
        pebbles = 0;
 
        for (int i = 0; i < line.length(); i++ )
            if ( line.at(i) == 'o') 
                pebbles++;
 
        solve(line, pebbles);
        printf ("%d\n", pebbles);
    }
 
    return 0;
}