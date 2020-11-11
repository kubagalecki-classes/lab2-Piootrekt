#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    //nie martwie sie o error na resource bo to jest header
    public:
    ResourceManager()
    {
      //konstruktor domyslny, tworzy resource i przypisuje go do res
      Resource* res_in = new Resource{};
      res=res_in;
      //delete res_in;
    }
    ResourceManager(ResourceManager& resm) : res{ resm.res } {}
    ResourceManager(ResourceManager&& resm) : res{resm.res}
    {
      //konstruktor przenoszacy - sprawdza, czy &resm i this to nie to samo,
      //jesli tak to nic nie rob
      //if (this==resm){}
      //else
      
      resm.res = nullptr;
      
    }
    ~ResourceManager()
    {
      //destruktor, niszczy wskaznik do res
      delete res;
    }
    ResourceManager& operator=(ResourceManager&& resm) 
    {
        res = nullptr;
        res = resm.res;
        //przenoszacy operator przypisania

        resm.res = nullptr;
        return *this;
    }
    ResourceManager& operator=(ResourceManager& resm)
    {
        res = nullptr;
        res = resm.res;
      //kopiujacy operator przypisania - zwalnia zasob na ktory wskazuje res i tworzy 
      //obiekt bedacy kopia resm.res i przypisuje do niego adres res
        return *this;
    }
    double get()
    {
      return res->get();  
    }
    private:
    Resource* res;
};