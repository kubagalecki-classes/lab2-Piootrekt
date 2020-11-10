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
      Resource res_in;
      res=res_in;
    }
    ResourceManager(ResourceManager& resm)
    {
      //konstruktor kopiujacy - w liscie inicjalizacyjnej tworzy nowy obiekt bedacy kopia resm.res
      //i przypisuje jego adres do res
    }
    ResourceManager(ResourceManager&& resm)
    {
      //konstruktor przenoszacy - sprawdza, czy &resm i this to nie to samo,
      //jesli tak to nic nie rob
      res = resm.res;
      resm.res = nullptr;
    }
    ~ResourceManager()
    {
      //destruktor, niszczy wskaznik do res
      delete res;
    }
    ResourceManager& operator=(ResourceManager&& resm)
    {
      //przenoszacy operator przypisania
      resm.res = nullptr;
    }
    ResourceManager operator=(ResourceManager& resm)
    {
      //kopiujacy operator przypisania - zwalnia zasob na ktory wskazuje res i tworzy 
      //obiekt bedacy kopia resm.res i przypisuje do niego adres res
    }
    double get()
    {
      return res->get();  //zle: passing 'const Resource' as 'this' argument discards qualifiers
    }
    private:
    Resource* res;
};