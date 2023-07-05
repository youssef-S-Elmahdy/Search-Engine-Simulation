//
//  main.cpp
//  Project
//
//  Created by Youssef Elmahdy on 25/11/2022.

#include<iostream>
#include<iterator>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    int x, y;
    string arr[10];
    string arr1[2];
    string arr2[2];
    vector<double> rank;
    vector<double> rank1;
    vector<string> out;
    vector<string> out1;
    vector<pair <double, string>> vec;
    vector<pair <double, string>> vec1;
    string s, q, aand = "AND", oor = "OR";

    while (true)
    {
        ifstream fs("/Users/youssef/Desktop/Semester 3/321 Lab/Project/Project/Webgraph.csv");
        ifstream fs1("/Users/youssef/Desktop/Semester 3/321 Lab/Project/Project/Keywords.csv");
        ifstream fs2("/Users/youssef/Desktop/Semester 3/321 Lab/Project/Project/Impressions.csv");

        cout << "Welcome!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1.  New Search" << endl;
        cout << "2.  Exit\n" << endl;
        cout << "Type in your choice: ";

        cin >> x;

        if (x == 1)
        {
            cout << "NOTE: If you are using windows, please usa a ',' instead of space when using AND or OR \n";
            cout << "Enter Your query: ";
            cin >> s;
            if (s[0] == '\"' && s[s.size() - 1] == '\"')
            {
                s.erase(s.begin() + 0);
                s.erase(s.begin() + s.size() - 1);
                if (fs1.is_open())
                {
                    while (!fs1.eof())
                    {
                        int p = 0;
                        getline(fs1, q);
                        stringstream ss(q);
                        while (!ss.eof())
                        {
                            getline(ss, arr[p], ',');
                            p++;
                        }
                        for (int i = 1; i < p;i++)
                        {
                            if (arr[i] == s)
                            {
                                out.push_back(arr[0]);
                                double z = 0;
                                while (!fs2.eof())
                                {
                                    int pp = 0;
                                    string qq;
                                    getline(fs2, qq);
                                    stringstream sss(qq);
                                    while (!sss.eof())
                                    {
                                        getline(sss, arr1[pp], ',');
                                        if (pp == 0)
                                            out1.push_back(arr1[0]);
                                        pp++;
                                    }
                                    z = stod(arr1[1]);
                                    rank1.push_back(z);
                                    rank.push_back(z);
                                }
                                break;
                            }
                        }
                    }
                }
            }
            else if (strstr(s.c_str(), aand.c_str()))
            {
                int tt = 0;
                string qr[2];
                istringstream st(s);
                while (!st.eof())
                {
                    getline(st, qr[tt], ',');
                    tt++;
                    if (qr[tt - 1] == "AND")
                        tt--;
                }

                if (fs1.is_open())
                {
                    while (!fs1.eof())
                    {
                        int p = 0;
                        getline(fs1, q);
                        stringstream ss(q);
                        while (!ss.eof())
                        {
                            getline(ss, arr[p], ',');
                            p++;
                        }
                        int ff = 0;
                        int ll = 0;
                        for (int i = 1; i < p;i++)
                        {
                            if (arr[i] == qr[0])
                                ff++;
                            else if (arr[i] == qr[1])
                                ll++;
                        }
                        if (ff >= 1 && ll >= 1)
                        {
                            out.push_back(arr[0]);
                            double z = 0;
                            while (!fs2.eof())
                            {
                                int pp = 0;
                                string qq;
                                getline(fs2, qq);
                                stringstream sss(qq);
                                while (!sss.eof())
                                {
                                    getline(sss, arr1[pp], ',');
                                    if (pp == 0)
                                        out1.push_back(arr1[0]);
                                    pp++;
                                }
                                z = stod(arr1[1]);
                                rank1.push_back(z);
                                rank.push_back(z);
                            }
                        }
                    }
                }
            }
            else if (strstr(s.c_str(), oor.c_str()))
            {
                int tt = 0;
                string qr[2];
                istringstream st(s);
                while (!st.eof())
                {
                    getline(st, qr[tt], ',');
                    tt++;
                    if (qr[tt - 1] == "OR")
                        tt--;
                }

                if (fs1.is_open())
                {
                    while (!fs1.eof())
                    {
                        int p = 0;
                        getline(fs1, q);
                        stringstream ss(q);
                        while (!ss.eof())
                        {
                            getline(ss, arr[p], ',');
                            p++;
                        }
                        for (int i = 1; i < p;i++)
                        {
                            if (arr[i] == qr[0] || arr[i] == qr[1])
                            {
                                out.push_back(arr[0]);
                                double z = 0;
                                while (!fs2.eof())
                                {
                                    int pp = 0;
                                    string qq;
                                    getline(fs2, qq);
                                    stringstream sss(qq);
                                    while (!sss.eof())
                                    {
                                        getline(sss, arr1[pp], ',');
                                        if (pp == 0)
                                            out1.push_back(arr1[0]);
                                        pp++;
                                    }
                                    z = stod(arr1[1]);
                                    rank1.push_back(z);
                                    rank.push_back(z);
                                }
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                int tt = 0;
                string qr[2];
                istringstream st(s);
                while (!st.eof())
                {
                    getline(st, qr[tt], ',');
                    tt++;
                }

                if (fs1.is_open())
                {
                    while (!fs1.eof())
                    {
                        int p = 0;
                        getline(fs1, q);
                        stringstream ss(q);
                        while (!ss.eof())
                        {
                            getline(ss, arr[p], ',');
                            p++;
                        }
                        for (int i = 1; i < p;i++)
                        {
                            if (arr[i] == qr[0] || arr[i] == qr[1])
                            {
                                out.push_back(arr[0]);
                                double z = 0;
                                while (!fs2.eof())
                                {
                                    int pp = 0;
                                    string qq;
                                    getline(fs2, qq);
                                    stringstream sss(qq);
                                    while (!sss.eof())
                                    {
                                        getline(sss, arr1[pp], ',');
                                        if (pp == 0)
                                            out1.push_back(arr1[0]);
                                        pp++;
                                    }
                                    z = stod(arr1[1]);
                                    rank1.push_back(z);
                                    rank.push_back(z);
                                }
                                break;
                            }
                        }
                    }
                }
            }

            if (fs2.is_open())
            {
                while (!fs2.eof())
                {
                    int pp = 0;
                    string qq;
                    getline(fs2, qq);
                    stringstream ssst(qq);
                    while (!ssst.eof())
                    {
                        getline(ssst, arr1[pp], ',');
                        if (pp == 0)
                            out1.push_back(arr1[0]);
                        else
                            rank1.push_back(stod(arr1[1]));
                        pp++;
                    }
                }
            }

            cout << "Search results:" << endl;

            for (int i = out.size() - 1;i >= 0;i--)
            {
                vec.push_back(make_pair(rank[i], out[i]));
            }

            for (int i = out1.size() - 1;i >= 0;i--)
            {
                vec1.push_back(make_pair(rank1[i], out1[i]));
            }

            sort(vec.begin(), vec.end());
            sort(vec1.begin(), vec1.end());

            for (int i = out.size() - 1;i >= 0;i--)
            {
                cout << out.size() - i << ".  " << vec[i].second << " & it's rank is: " << vec[i].first << endl;
            }

            cout << "\nWould you like to" << endl;
            cout << "1.  Choose a webpage to open" << endl;
            cout << "2.  New search" << endl;
            cout << "3.  Exit\n" << endl;
            cout << "Type in your choice: ";
            cin >> x;
            ofstream fs3("Test2.txt");
            int y = 0;
            double ptr = 0;
            switch (x)
            {
                case 1:
                    cout << "\nEnter the webpage's rank: ";
                    cin >> x;

                    while (!fs.eof())
                    {
                        string qwe = vec[out.size() - x].second;
                        int ppp = 0;
                        string qqq;
                        getline(fs, qqq);
                        stringstream ssss(qqq);
                        while (!ssss.eof())
                        {
                            getline(ssss, arr2[ppp], ',');
                            ppp++;
                        }
                        if (arr2[0] == qwe || arr2[1] == qwe)
                            y++;
                    }
                    ptr = vec[out.size() - x].first;
                    vec[out.size() - x].first = (0.4 * vec[out.size() - x].first) + ((1 - ((0.1 * y) / (1 + 0.1 * y)) * vec[out.size() - x].first + ((0.1 * y) / (1 + 0.1 * y)) * vec[out.size() - x].first++) * 0.4);
                    cout << "\nYou're now viewing " << vec[out.size() - x].second << endl;//s rank is: " <<endl;//<< vec[out.size() - x].first << endl;
                    vec[out.size() - x].first = ptr + ptr / vec[out.size() - x].first;
                    for (int i = 0;i < out1.size();i++)
                    {
                        if (vec1[i].second == vec[out.size() - x].second)
                            vec1[i].first = vec[out.size() - x].first;
                    }
                    cout << "Would you like to" << endl;
                    cout << "1.  Back to search results" << endl;
                    cout << "2.  New search" << endl;
                    cout << "3.  Exit\n" << endl;
                    cout << "Type in your choice: ";
                    cin >> x;
                    if (x == 1)
                    {
                        cout << "Search results:" << endl;
                        sort(vec.begin(), vec.end());
                        sort(vec1.begin(), vec1.end());
                        for (int i = out.size() - 1;i >= 0;i--)
                        {
                            cout << out.size() - i << ".  " << vec[i].second << " & it's rank is: " << vec[i].first << endl;
                        }
                        for (int i = 0;i < out1.size();i++)
                        {
                            fs3 << vec1[i].second << "," << vec1[i].first << endl;
                        }
                        cout << "\n";
                        vec.clear();
                        out.clear();
                        rank.clear();
                        vec1.clear();
                        out1.clear();
                        rank1.clear();
                    }
                    else if (x == 2)
                    {
                        for (int i = 0;i < out1.size();i++)
                        {
                            fs3 << vec1[i].second << "," << vec1[i].first << endl;
                        }
                        cout << "\n";
                        vec.clear();
                        out.clear();
                        rank.clear();
                        vec1.clear();
                        out1.clear();
                        rank1.clear();
                        break;
                    }
                    else
                    {
                        for (int i = 0;i < out1.size();i++)
                        {
                            fs3 << vec1[i].second << "," << vec1[i].first << endl;
                        }
                        vec.clear();
                        out.clear();
                        rank.clear();
                        vec1.clear();
                        out1.clear();
                        rank1.clear();
                        exit(1);
                    }
                    break;
                case 2:
                    for (int i = 0;i < out1.size();i++)
                    {
                        fs3 << vec1[i].second << "," << vec1[i].first << endl;
                    }
                    cout << "\n";
                    vec.clear();
                    out.clear();
                    rank.clear();
                    vec1.clear();
                    out1.clear();
                    rank1.clear();
                    break;
                case 3:
                    for (int i = 0;i < out1.size();i++)
                    {
                        fs3 << vec1[i].second << "," << vec1[i].first << endl;
                    }
                    exit(1);
                    break;
                default:
                    for (int i = 0;i < out1.size();i++)
                    {
                        fs3 << vec1[i].second << "," << vec1[i].first << endl;
                    }
                    cout << "\nEnter correct option\n";
                    break;
            }
        }
        else
            exit(1);
    }
    return 0;
}
