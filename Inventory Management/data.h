#ifndef DATA_H
#define DATA_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Item{
    private:
        string id;
        string name;
        int price;
        int quantity;
    public:
        Item(){}
        Item(string id, string name, int price, int quantity){
            this->id = id;
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }
        void set_id(string id){
            this->id = id;
        }
        void set_name(string name){
            this->name = name;
        }
        void set_quantity(int quantity){
            this->quantity = quantity;
        }
        void set_price(int price){
            this->price = price;
        }
        string get_id(){
            return this->id;
        }
        string get_name(){
            return this->name;
        }
        int get_quantity(){
            return this->quantity;
        }
        int get_price(){
            return this->price;
        }
};

class Storage{
    private:
        vector<Item> item;
    public:
        void my_replace(string &str,const string& oldstr,const string& newstr){
            string::size_type pos = 0u;
            while ((pos = str.find(oldstr,pos))!= string::npos){
                str.replace(pos,oldstr.length(),newstr);
                pos += newstr.length();
            }
        }
        bool read(string txt){
            string id,name,price,qty;
            ifstream file;
            file.open(txt);
            if (file.is_open()){
                while (file >> id >> name >> price >> qty){
                    my_replace(name,"-"," ");
                    add(Item(id,name,stoi(price),stoi(qty)));
                }
                file.close();
                return true;
            }
            else {
                return false;
            }
        }
        void write(string txt){
            string id,name,price,qty;
            ofstream file;
            file.open(txt);
            while (file.good()){
                for (vector<Item>::iterator it = item.begin(); it != item.end(); it++){
                    id = it->get_id();
                    name = it->get_name();
                    my_replace(name," ","-");
                    price = to_string(it->get_price());
                    qty = to_string(it->get_quantity());
                    file << id << " " << name << " " << price << " " << qty << endl;
                }
                file.close();
            }
        }

        void del(string id){
            for (int i = 0 ; i < item.size() ; i++){
                if (item[i].get_id() == id){
                    item.erase(item.begin()+i);
                }
            }
        }
        void add (Item a){
            this->item.push_back (a);
        }
        bool find_id(string id){
            for (int i = 0 ; i < item.size() ; i++){
                if (item[i].get_id() == id){
                    return true;
                }
            }
            return false;
        }
        Item* get_id(string id){
            for (int i = 0 ; i < item.size() ; i++){
                if (item[i].get_id() == id){
                    return &item[i];
                }
            }
        }
        void add_stock(string id, int quantity){
            int i;
            for (i = 0 ; i < item.size() ; i++){
                if (item[i].get_id() == id){
                    item[i].set_quantity(item[i].get_quantity() + quantity);
                    break;
                }
            }
        }
        void sell_stock(string id, int quantity){
            int i;
            for (i = 0 ; i < item.size() ; i++){
                if (item[i].get_id() == id ){
                    item[i].set_quantity(item[i].get_quantity() - quantity);
                    break;
                }
            }
        }
        vector<Item> get_vector(){
            return item;
        }
        void empty(){
            item.clear();
        }
};

#endif // DATA_H
