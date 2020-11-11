#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    //nie martwie sie o error na resource bo to jest header
    public:
    ResourceManager() : res{new Resource}
    {
      //konstruktor domyslny, tworzy resource i przypisuje go do res
      
      //delete res_in;
    }
    ResourceManager(const ResourceManager& resm) : res{ resm.res } 
    {
        //konstruktor kopiujacy - tworzy nowy obiekt bedacy kopia resm.res
    }
    ResourceManager(ResourceManager&& resm)
    {
      //konstruktor przenoszacy 
      res = resm.res;
      resm.res = nullptr;      
    }
    ~ResourceManager()
    {
      //destruktor, niszczy to na co wskazuje r
      //res = nullptr;
        if (res==nullptr){}
        else
        {
            delete res;
        }
    }
    ResourceManager& operator=(ResourceManager& resm)
    {
        //sprawdza, czy& resm i this to nie to samo,
        //jesli tak to nic nie rob
        if (res == resm.res) {}
        else
        {
            res = nullptr;
            res = resm.res;
        }
        //kopiujacy operator przypisania - zwalnia zasob na ktory wskazuje res i tworzy 
        //obiekt bedacy kopia resm.res i przypisuje do niego adres res
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& resm) 
    {
        //przenoszacy operator przypisania
        //sprawdza, czy& resm i this to nie to samo,
        //jesli tak to nic nie rob
        if (res == resm.res) {}
        else
        {
            res = nullptr;
            res = resm.res;
        }
        
        resm.res = nullptr;
        
        return *this;
    }
    
    double get()
    {
      return res->get();  
    }
    private:
    Resource* res;
};