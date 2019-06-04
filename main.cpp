#include <iostream>
#include <vector>
//variant 13 Nikonorov
using namespace std;

const size_t max_width = 80;
const size_t oformlenie = 4;
const size_t data_width = max_width - oformlenie;

int
main()
{

    size_t raz_mas;
    cerr << "Vvedite kolichestvo chisel" << endl;
    cin >> raz_mas;

    vector<double> massiv(raz_mas, 0);
    cerr << "\nVvedite massiv\n";
    for(size_t i=0; i<raz_mas; i++)
    {
        cin >> massiv[i];
    }
    int oc=0;
    while (true)
    {
        size_t kol_stolb;

        cerr << "\nVvedite kolichestvo stolb\n";
        cin >> kol_stolb;

        double max=massiv[1], min=max;
        for (double chislo: massiv)
        {
            if (min > chislo)
                min = chislo;
            if (max < chislo)
                max = chislo;
        }
        vector<size_t>stolb(kol_stolb, 0);

        for (double chislo: massiv)
        {
            size_t f=(size_t)((chislo-min)/(max-min)*kol_stolb);
            if (chislo == max)
            {
                f--;
            };
            stolb[f]++;
        }
        cerr << endl;

        size_t max_stolb = stolb[0];
        for (size_t chislo: stolb)
        {
            if(max_stolb < chislo)
            {
                max_stolb = chislo;
            }
        }
        double coeff = (double)data_width  / max_stolb;
        bool flag= false;
        if (max_stolb > data_width)
        {
            flag = true;
        }



        for (size_t chislo: stolb)
        {
            if (chislo < 10)
            {
                cout << " ";
            }
            if (chislo < 100)
            {
                cout << " ";
            }
            cout << chislo << "|";
            size_t height;

            if (flag)
            {
                height = (size_t)(chislo * coeff);
            }
            else
            {
                height = chislo;
            }
            for (size_t i = 0; i < height; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
        cout << "dovol`ni li vi rezul`tatom?1/0?"<< endl;
        cin >> oc;
        if (oc == 1 )
        {

            break;
        }
    else {
        cout<<"Oshibka vvedite zanogo"<<endl;
    }
    }


}

