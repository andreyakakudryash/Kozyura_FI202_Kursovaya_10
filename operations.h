#include <iostream>
#include <string>
#include "objects.h"
#include <fstream>

using namespace std;

class recordedit {
private:
    customerData client;
    cargoData goods;
    transportData trans;

public:
    recordedit() {

    }


    recordedit(const string& name, const string& surname, const string& number, const string& cargo, const int& weight, const float& volume, const string& trasnport) {
        this->client = *(new customerData(name, surname, number));
        this->goods = *(new cargoData(cargo, weight, volume));
        this->trans = *(new transportData(trasnport));
    }

    customerData getClient() {
        return client;
    }

    cargoData getGoods() {
        return goods;
    }

    transportData getTrans() {
        return trans;
    }

    void print() {
        client.print();
        goods.print();
        trans.print();
    }
    void edit() {
        cout << "�������� �����, ������� �� ������� ��������:\n";
        cout << "1 - ������������ ������\n";
        cout << "2 - �������� �����\n";
        cout << "3 - ��� �����\n";
        cout << "4 - ����� �����\n";
        cout << "5 - ��� ����������\n";

        int choose;
        cin >> choose;
        while (choose < 1 || choose>5) {
            cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���\n";
            cin >> choose;
        }
        switch (choose) {
        case 1:
        {
            string surname, name, number;
            cout << "�������: ";
            cin >> surname;
            cout << "���: ";
            cin >> name;
            cout << "����� ��������: ";
            cin >> number;
            client = customerData(surname, name, number);
            break;
        }
        case 2:
        {
            vector<string> typeCargo = goods.getType_cargo();
            int select = 0;
            string other;
            cout << "�������� �������� �����: " << endl;

            for (int i = 0; i < typeCargo.size(); i++) {
                cout << i + 1 << ". " << typeCargo[i] << endl;
            }

            cin >> select;
            while (select < 1 || select>typeCargo.size()) {
                cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
                cin >> select;
            }
            if (typeCargo[select - 1] == "������") {
                cout << "������� ���� �������: ";
                cin >> other;
                goods = cargoData(other, goods.getWeight(), goods.getVolume());
            }
            else {
                goods = cargoData(typeCargo[select - 1], goods.getWeight(), goods.getVolume());
            }
            break; }
        case 3:
        {
            int weight;
            cout << "������� ��� ����� (� ��.): ";
            cin >> weight;
            goods = cargoData(goods.getCargo(), weight, goods.getVolume());
            break;
        }
        case 4:
        {
            int volume;
            cout << "������� ����� ����� (� ���. �.): ";
            cin >> volume;
            goods = cargoData(goods.getCargo(), goods.getWeight(), volume);
            break;
        }

        case 5:
        {
            int select = 0;
            vector<string> typeTrans = trans.get_vector_transport();
            cout << "�������� ��� ����������, ������� ���������� ����������� ��������: " << endl;

            for (int i = 0; i < typeTrans.size(); i++) {
                cout << i + 1 << ". " << typeTrans[i] << endl;
            }

            cin >> select;
            while (select < 1 || select>typeTrans.size()) {
                cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
                cin >> select;
            }

            trans = transportData(typeTrans[select - 1]);
        }

        default:
            break;
        }
    }
};


class main_operations {
private:

    int n = 0;
    recordedit* order;
    customerData client;
    cargoData goods;
    transportData trans;


public:

    main_operations() {
        setlocale(LC_ALL, "RU");
        order = new recordedit[n + 1];
        vector<string> typeCargo = goods.getType_cargo();
        int select;
        string other;
        cout << "�������� �������� �����: " << endl;
        for (int i = 0; i < typeCargo.size(); i++) {
            cout << i + 1 << ". " << typeCargo[i] << endl;
        }
        cin >> select;
        while (select < 1 || select>typeCargo.size()) {
            cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
            cin >> select;
        }
        if (typeCargo[select - 1] == "������") {
            cout << "������� ���� �������: ";
            cin >> other;
            goods = cargoData(other, goods.getWeight(), goods.getVolume());
        }
        else {
            goods = cargoData(typeCargo[select - 1], goods.getWeight(), goods.getVolume());
        }

        int weight;
        cout << "������� ��� ����� (� ��.): ";
        cin >> weight;
        goods = cargoData(goods.getCargo(), weight, goods.getVolume());

        float volume;
        cout << "������� ����� ����� (� ���. �.): ";
        cin >> volume;
        goods = cargoData(goods.getCargo(), goods.getWeight(), volume);

        int select2 = 0;
        vector<string> typeTrans = trans.get_vector_transport();
        cout << "�������� ��� ����������, ������� ���������� ����������� ��������: " << endl;

        for (int i = 0; i < typeTrans.size(); i++) {
            cout << i + 1 << ". " << typeTrans[i] << endl;
        }
        cin >> select2;
        while (select2 < 1 || select2>typeTrans.size()) {
            cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
            cin >> select2;
        }
        trans = transportData(typeTrans[select2 - 1]);
        string surname, name, number;
        cout << "�������: ";
        cin >> surname;
        cout << "���: ";
        cin >> name;
        cout << "����� ��������: ";
        cin >> number;
        order[n] = recordedit(surname, name, number, goods.getCargo(), weight, volume, typeTrans[select2 - 1]);
        n++;
    }

    ~main_operations() {
        delete[] order;
    }

    void print() {
        setlocale(LC_ALL, "RU");
        for (int i = 0; i < n; i++) {
            recordedit current_indent;
            current_indent = order[i];
            cout << "[" << i + 1 << "] ";
            current_indent.print();
            cout << endl;

        }
    }

    void addOrder() {
        recordedit* neworder = new recordedit[n + 1];
        vector<string> typeCargo = goods.getType_cargo();
        int select;
        string other;
        cout << "�������� �������� �����: " << endl;
        for (int i = 0; i < typeCargo.size(); i++) {
            cout << i + 1 << ". " << typeCargo[i] << endl;
        }
        cin >> select;
        while (select < 1 || select>typeCargo.size()) {
            cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
            cin >> select;
        }
        if (typeCargo[select - 1] == "������") {
            cout << "������� ���� �������: ";
            cin >> other;
            goods = cargoData(other, goods.getWeight(), goods.getVolume());
        }
        else {
            goods = cargoData(typeCargo[select - 1], goods.getWeight(), goods.getVolume());
        }

        int weight;
        cout << "������� ��� ����� (� ��.): ";
        cin >> weight;
        goods = cargoData(goods.getCargo(), weight, goods.getVolume());

        float volume;
        cout << "������� ����� ����� (� ���. �.): ";
        cin >> volume;
        goods = cargoData(goods.getCargo(), goods.getWeight(), volume);

        int select2 = 0;
        vector<string> typeTrans = trans.get_vector_transport();
        cout << "�������� ��� ����������, ������� ���������� ����������� ��������: " << endl;

        for (int i = 0; i < typeTrans.size(); i++) {
            cout << i + 1 << ". " << typeTrans[i] << endl;
        }
        cin >> select2;
        while (select2 < 1 || select2>typeTrans.size()) {
            cout << "�� ���������� ������ ��� ������ �������, ����������, ���������� ��� ���" << endl;
            cin >> select2;
        }
        trans = transportData(typeTrans[select2 - 1]);
        string surname, name, number;
        cout << "�������: ";
        cin >> surname;
        cout << "���: ";
        cin >> name;
        cout << "����� ��������: ";
        cin >> number;

        for (int i = 0; i < n; i++) {
            neworder[i] = order[i];
        }

        neworder[n] = recordedit(surname, name, number, goods.getCargo(), weight, volume, typeTrans[select2 - 1]);

        delete[] order;

        order = neworder;
        n++;
    }


    void  deleteOrder(int s) {
        recordedit* neworder = new recordedit[n - 1];

        if (s >= 1 && s <= n) {
            int newIndex = 0;
            for (int i = 0; i < n; i++) {
                if (i != s - 1) {
                    neworder[newIndex] = order[i];
                    newIndex++;
                }
            }

            delete[] order;

            order = neworder;
            n--;
        }

        else {
            cout << "��� ������ �������� ����� ������, ����������, ���������� ��� ���";
        }

    }

    void editOrder(int s) {
        order[s - 1].edit();
    }


    void saveToFile() {
        ofstream fout;

        try
        {
            fout.open("orders.txt", ofstream::app);
        }
        catch (const exception& e) {
            cout << "������ �������� �����";
            cout << e.what() << endl;
            return;

        }

        if (fout.is_open()) {

            string str_file;
            for (int i = 0; i < n; i++) {
                recordedit current_order = order[i];
                str_file = current_order.getClient().getSurname() + "___" + current_order.getClient().getName() +
                    "___" + current_order.getClient().getNumber() + "___" + current_order.getGoods().getCargo() +
                    "___" + to_string(current_order.getGoods().getWeight()) + "___" + to_string(current_order.getGoods().getVolume()) +
                    "___" + current_order.getTrans().getTransport();
                fout << str_file << endl;
            }

            fout.close();
        }


    }

    void deleteFromFile() {
        ofstream fout;

        try
        {
            fout.open("orders.txt", ofstream::out | ofstream::trunc);
        }
        catch (const exception& e) {
            cout << "������ �������� �����";
            cout << e.what() << endl;
            return;
        }

        if (fout.is_open()) {
            fout.close();
        }

        else {
            cout << "��� �������� ������ �� ����� ��������� ������" << endl;
        }

    }


    void orderFromFile(recordedit& newstr) {
        recordedit* neworder = new recordedit[n + 1];
        for (int i = 0; i < n; i++) {
            neworder[i] = order[i];
        }
        neworder[n] = newstr;
        n++;
        delete[]order;
        order = neworder;
    }

    void loadFromFile() {
        setlocale(LC_ALL, "ru");

        ifstream fin;

        try
        {
            fin.open("orders.txt");
        }
        catch (const exception& e) {
            cout << "������ �������� �����";
            cout << e.what() << endl;
            return;

        }

        if (fin.is_open()) {

            string newstr;

            while (getline(fin, newstr)) {
                string separator = "___";
                vector <string> values;
                size_t pos = 0;
                while ((pos = newstr.find(separator)) != string::npos) {
                    string value = newstr.substr(0, pos);
                    values.push_back(value);
                    newstr.erase(0, pos + separator.length());
                }
                values.push_back(newstr);

                if (values.size() >= 7) {
                    string surname = values[0];
                    string name = values[1];
                    string number = values[2];
                    string cargo = values[3];
                    int weight = stoi(values[4]);
                    float volume = stof(values[5]);
                    string transport = values[6];
                    recordedit* newRecord = new recordedit(surname, name, number, cargo, weight, volume, transport);
                    orderFromFile(*newRecord);
                }

            }

        }

        fin.close();
    }


};
