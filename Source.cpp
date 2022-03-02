#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <set>
#include <fstream>
using namespace std;

class Gibbet final
{
private:
    ifstream ff;
    string s;
    unordered_set<char>guess;

    static const vector<string> v;

public:
    Gibbet() = default;
    explicit Gibbet(const string& f) :
        ff(f),
        s(istream_iterator<char>(ff), istream_iterator<char>())
    {
        Play();
    }

    Gibbet(const Gibbet& g) = delete;
    Gibbet& operator=(const Gibbet& g) = delete;
    Gibbet(const Gibbet&& g) = delete;
    Gibbet& operator=(const Gibbet&& g) = delete;
    ~Gibbet() {}

    void Play();

};
void Gibbet::Play() {

    bool g = false; char ch{}; int c{};

    while (true)
    {
        cout << "Enter a symbol: " << endl;
        cin >> ch;

        ch = tolower(ch);

        if (s.find(ch) != string::npos && guess.find(ch) == guess.end())
        {
            guess.insert(ch);

            replace_copy_if(s.cbegin(), s.cend(), ostream_iterator<char>(cout), [this](const char& cc) {
                return guess.find(cc) == guess.end();
                }, '#');

            cout << endl;

            if (all_of(s.cbegin(), s.cend(), [this](const char& cc) {  return guess.find(cc) != guess.end(); }))
            {
                g = true;
                break;
            }
        }
        else
        {
            system("cls");
            cout << v[c] << endl; ++c;
            if (c == v.size()) break;

        }

    }

    cout << "U " << (g ? "WIN!" : "LUSE! \nWord is " + s) << endl;

}
const vector<string> Gibbet::v{

    {
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      /   \\           $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "                      $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    },
    {
        "        $$$$$$$$$$$$$$$\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        |             $\n"
        "        O             $\n"
        "      / | \\           $\n"
        "        |             $\n"
        "       / \\            $\n"
        "                      $\n"
        "                      $\n"
        " $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
        " $                          $\n"
    }
};
int main() {
    string s{ "tr.txt" };
    Gibbet g(s);
    return 0;
}