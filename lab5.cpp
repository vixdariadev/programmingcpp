#include <iostream>
#include <string>
 
class Animal {
    protected:
        std::string name;
        int age;
 
    public:
        Animal(std::string n, int a);
        virtual void makeSound();
        virtual void eat(); // бажано використовувати virtual через поліморфізм та унаслідування
        virtual void sleep();
};
 
class Mammal : public Animal { //дані були захищені, тому ми не могли їх використовувати і використовуємо public для наслідування
    protected:
    bool isSleeping; // помилки в коді виникають через цей getSleeping, тому міняємо на isSleeping
 
    public:
        Mammal(std::string n, int a);
        void makeSound();
        void eat();
        void sleep();
};
 
class Dog : public Mammal {
    private:
        bool isTailWagging;
 
    public:
        Dog(std::string n, int a);
        void makeSound();
        void eat();
        void sleep();
        void fetch();
        void wagTail();
};
 
class Cat : public Mammal {
    private:
        int numberOfLives;
 
    public:
        Cat(std::string n, int a);
        void makeSound();
        void eat();
        void sleep();
};
 
class Tail : public Dog {
    public:
        Tail(std::string n, int a);
};
 
Animal::Animal(std::string n, int a) {
    name = n;
    age = a;
  }
 
  void Animal::makeSound() {
    std::cout << "This is a generic animal sound." << std::endl;
  }
 
  void Animal::eat() { std::cout << "The animal is eating." << std::endl; }
 
  void Animal::sleep() { std::cout << "The animal is sleeping." << std::endl; }
 
  Mammal::Mammal(std::string n, int a) : Animal(n, a) , isSleeping(false) {}; // була помилка в назві булевої змінної, також передаємо в енімал аргумент а
 
  void Mammal::makeSound() {
    std::cout << "This is a generic mammal sound." << std::endl;
  }
 
  void Mammal::eat() { std::cout << "The mammal is eating." << std::endl; }
 
  void Mammal::sleep() {
    std::cout << "The mammal is sleeping." << std::endl;
    isSleeping = true;
  }
 
  Dog::Dog(std::string n, int a) : Mammal(n, a) , isTailWagging(false) {}; //не правильно записан метод ініціалізації, булева змінна має бути перед {} а не в них
 
  void Dog::makeSound() { std::cout << "Woof!" << std::endl; }
 
  void Dog::eat() { std::cout << "The dog is eating." << std::endl; }
 
  void Dog::sleep() {
    std::cout << "The dog is sleeping." << std::endl;
    isSleeping = true;
  }
 
  void Dog::fetch() { std::cout << "The dog is fetching." << std::endl; }
 
  void Dog::wagTail() {
    if (isSleeping) {
      std::cout << "The dog can't wag its tail because it's sleeping."
                << std::endl;
    } else {
      std::cout << "The dog is wagging its tail." << std::endl;
      isTailWagging = true;
    }
  }
 
  Cat::Cat(std::string n, int a) : Mammal(n, a) , numberOfLives(9) {};//не правильно записан метод ініціалізації, кількість життів має бути до дужок
 
  void Cat::makeSound() { std::cout << "Meow!" << std::endl; }
 
  void Cat::eat() { std::cout << "The cat is eating." << std::endl; }
 
  void Cat::sleep() {
    std::cout << "The cat is sleeping." << std::endl;
    isSleeping = true;
  }
 
  Tail::Tail(std::string n, int a) : Dog(n, a) {}// Dog має конструктор, який приймає два параметри, тому ми повинні викликати його конструктор з відповідними аргументами
 
  //int Cat::eat=eat(); // не правильно записано, оскільки eat() є методом, а не змінною, тому ми не можемо присвоїти його значення змінній
 
int main() {
  Dog d("Fido", 3);
  Cat c("Fluffy", 5);
  Dog d1("Barky", 3);
 
  Mammal *arr[] = {&d, &c, &d1};
 
  // should woof, meow, woof
  for (int i = 0; i < 3; i++){
    arr[i]->makeSound();
  }
 
  // should eat in dog, cat, dog order
  for (int i = 0; i < 3; i++){
    arr[i]->eat();
  }
 
  // should woof, meow, woof
  for (int i = 0; i < 3; i++){
    arr[i]->makeSound();
  }
 
  // should sleep in dog, cat, dog order
  for (int i = 0; i < 3; i++){
    arr[i]->sleep();
  } 
 
  // shoudn't do anything as they're sleeping
  for (int i = 0; i < 3; i++){
    arr[i]->makeSound();
  }
 
  // shoudn't eat actually, as they are sleeping
  for (int i = 0; i < 3; i++){
    arr[i]->eat();
  }
// shouldn't wag tails, they are sleeping, but some of them do not wag tail at all
  //for (int i = 0; i < 3; i++){ у нас немає методу wagTail() у класі Mammal, і ми не можеио це зробити тому що деякі об.єкти масиву є котами і в них немає цього методу
   // arr[i]->wagTail();
  //}
 for (int i=0; i<3; i++){
    Dog* dog = dynamic_cast<Dog*>(arr[i]);// використовючи поліморфізм ми можемо використати dynamic_cast, оскільки в нас є вказівник на батьківський клас, але нам потрібно отримати доступ до даних які є лише у дочірньому класі 
    if(dog){
        dog->wagTail();
    }
 }
  // do they really need to sleep forever? :'(
 
  // Hah, that's stange :)
  Tail t("Taily", 2);
  t.makeSound();
}