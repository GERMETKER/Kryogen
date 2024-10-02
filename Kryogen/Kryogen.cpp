#include <iostream>
#include <string>

class Cat
{
public:
    Cat()
    {
        name_ = "Niga";
        age_ = 2;
        sex_ = false;
    }
    Cat(std::string name, int age, bool sex)
    {
        name_ = name;
        age_ = age;
        sex_ = sex;
    }
    std::string GetName()
    {
        return name_;
    }
    int GetAge()
    {
        return  age_;
    }
    bool GetSex()
    {
        return sex_;
    }
    void SetName(std::string name)
    {
        name_ = name;
    }
    void SetAge(int age)
    {
    age_ = age;
    }
    void SetSex(bool sex)
    {
        sex_ = sex;
    }
    std::string Info()const
    {
        std::string info;
        info = "Name: " + name_ + ", ";
        info += "Age: " + std::to_string(age_) + ", ";
        info += "Sex: " + (sex_)? "male":"female";
        return info;
    }
private:
    std::string name_;
    int age_;
    bool sex_;

};

class ZooMotel
{
public:
    ZooMotel()
    {
        name_ = "Default Motel";
        cats_ = nullptr;
        countOfCats_ = 0; 
    }
    ZooMotel(const ZooMotel& other)
    {
        name_ = other.name_;
        countOfCats_ = other.countOfCats_;
        cats_ = new Cat[countOfCats_];
        for (int i = 0; i < countOfCats_; i++)
        {
            cats_[i] = other[i];
        }
    }
    ZooMotel(ZooMotel&& other)
    {
        name_ = "Default Motel";
        cats_ = nullptr;
        countOfCats_ = 0;
        std::swap(name_, other.name_);
        std::swap(cats_, other.cats_);
        std::swap(countOfCats_, other.countOfCats_);

    }
    void AddCat(Cat& newCat)
    {
        if (!cats_)
        {
            countOfCats_ += 1;
            cats_ = new Cat[countOfCats_]{};
            cats_[countOfCats_ - 1] = newCat;
        }
        else
        {
            auto tmp = new Cat[countOfCats_ + 1]{};
            for (int i = 0l; i < countOfCats_; i++)
            {
                tmp[i] = cats_[i];
            }
            tmp[countOfCats_] = newCat;
            countOfCats_ += 1;
            std::swap(tmp, cats_);
            delete[]tmp;
        }
    }
    void KickOut(int i)
    {
        if (countOfCats_ == 1)
        {
            delete[]cats_;
            cats_ = nullptr;
            countOfCats_ = 0;
            return;
        }
        else if (cats_)
        {
            auto tmp = new Cat[countOfCats_ - 1]{};
            for (int j = 0; j < i; j++)
            {
                tmp[j] = cats_[j];
            }
            for (int j = i + 1; j < countOfCats_; j++)
            {
                tmp[j - 1] = cats_[j];
            }
            std::swap(tmp, cats_);
            delete[]tmp;
            countOfCats_ -= 1;
        }
    }
    ~ZooMotel()
    {
        if (cats_)
        {
            delete[]cats_;
        }
    }
    int Size()const
    {
        return countOfCats_;
    }
    Cat& operator[](int i)
    {
        return cats_[i];
    }
    const Cat& operator[](int i)const
    {
        return cats_[i];
    }
private:
    std::string name_;
    Cat* cats_;
    int countOfCats_;
};

void BlackMagic(ZooMotel zero)
{

}

int main()
{
    ZooMotel hotel;
    Cat Jamal;
    Jamal.SetName("Jamal");
    Jamal.SetAge(4);
    Jamal.SetSex(false);
    hotel.AddCat(Jamal);
    std::cout << hotel[0].Info() << "\n";
    //Агрегация - способ связи классов в котором класс хранения не несёт
    // ответственности за время жизни самого компанента.
    // - способ связи классов в котором отсутсвие компонента не приведёт к нерабооспособности хранителя
    BlackMagic(hotel);
    //Композиция - способ связи классов при котором класс хранения несёт ответствнность за время жизни компонента \
    // и имеет общее время жизни с компонентом

}


