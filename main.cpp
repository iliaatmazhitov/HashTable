#include "UI.h"
#include "Person.h"
#include "KeySpace.h"

int main() {
    HashTable<Person> h1(3);
    Person p1("Ivan", 19);
    Person p2("Nikolay", 19, "4529", "866678");
    Person p3("Ilya", 19, "2929", "998774");
    Person p4("Petr", 18, "1535", "47748");
    Person p5("Maxim", 19, "6789", "123456");
    Person p6("Denis", 17, "1525", "354555");
    Person p7("Anna", 25, "7890", "234567");
    Person p8("Olga", 30, "3456", "789012");
    Person p9("Sergey", 22, "9012", "345678");
    Person p10("Dmitry", 28, "5678", "901234");

    h1.Insert("HR", p7);
    h1.Insert("Managers", p8);
    h1.Insert("Developers", p9);
    h1.Insert("Designers", p10);

    Person p11("Elena", 27, "1234", "567890");
    Person p12("Andrey", 33, "7890", "123456");
    Person p13("Tatiana", 29, "4567", "890123");
    Person p14("Alexey", 31, "0123", "456789");
    Person p15("Maria", 26, "6789", "012345");

    h1.Insert("Accountants", p11);
    h1.Insert("Sales", p12);
    h1.Insert("Marketing", p13);
    h1.Insert("Support", p14);
    h1.Insert("QA", p15);


// Продолжаем добавлять еще 85 записей...

    Person p16("Vladimir", 35, "2345", "678901");
    Person p17("Ekaterina", 24, "8901", "234567");
    Person p18("Nikolai", 29, "5678", "901234");
    Person p19("Irina", 27, "1234", "567890");
    Person p20("Mikhail", 32, "7890", "123456");

    h1.Insert("Analysts", p16);
    h1.Insert("Researchers", p17);
    h1.Insert("Testers", p18);
    h1.Insert("Designers", p19);
    h1.Insert("Managers", p20);

// ... продолжайте в том же духе, создавая новые объекты Person
// и вставляя их в хеш-таблицу с различными ключами

    Person p96("Boris", 45, "6789", "012345");
    Person p97("Galina", 38, "2345", "678901");
    Person p98("Yuri", 29, "8901", "234567");
    Person p99("Valentina", 33, "4567", "890123");
    Person p100("Grigory", 27, "0123", "456789");

    h1.Insert("Directors", p96);
    h1.Insert("Consultants", p97);
    h1.Insert("Trainers", p98);
    h1.Insert("Coordinators", p99);
    h1.Insert("Specialists", p100);

    Person p101("Svetlana", 28, "5678", "901234");
    Person p102("Igor", 36, "1234", "567890");
    Person p103("Natalya", 31, "7890", "123456");
    Person p104("Oleg", 29, "3456", "789012");
    Person p105("Ksenia", 25, "9012", "345678");

    h1.Insert("Lawyers", p101);
    h1.Insert("Engineers", p102);
    h1.Insert("Accountants", p103);
    h1.Insert("Developers", p104);
    h1.Insert("Designers", p105);

    Person p106("Artem", 33, "5678", "901234");
    Person p107("Polina", 27, "1234", "567890");
    Person p108("Roman", 30, "7890", "123456");
    Person p109("Alina", 26, "3456", "789012");
    Person p110("Vadim", 34, "9012", "345678");

    h1.Insert("Managers", p106);
    h1.Insert("HR", p107);
    h1.Insert("Sales", p108);
    h1.Insert("Marketing", p109);
    h1.Insert("Support", p110);

    Person p111("Yulia", 29, "5678", "901234");
    Person p112("Stanislav", 35, "1234", "567890");
    Person p113("Evgenia", 28, "7890", "123456");
    Person p114("Kirill", 32, "3456", "789012");
    Person p115("Daria", 27, "9012", "345678");

    h1.Insert("Analysts", p111);
    h1.Insert("Researchers", p112);
    h1.Insert("Testers", p113);
    h1.Insert("Programmers", p114);
    h1.Insert("Designers", p115);

    Person p116("Timur", 31, "5678", "901234");
    Person p117("Veronika", 26, "1234", "567890");
    Person p118("Gleb", 33, "7890", "123456");
    Person p119("Karina", 29, "3456", "789012");
    Person p120("Leonid", 35, "9012", "345678");

    h1.Insert("Economists", p116);
    h1.Insert("Coders", p117);
    h1.Insert("Managers", p118);
    h1.Insert("HR", p119);
    h1.Insert("Sales", p120);

    Person p121("Yana", 28, "5678", "901234");
    Person p122("Ruslan", 34, "1234", "567890");
    Person p123("Zlata", 27, "7890", "123456");
    Person p124("Mikhail", 30, "3456", "789012");
    Person p125("Nina", 32, "9012", "345678");

    h1.Insert("Marketing", p121);
    h1.Insert("Support", p122);
    h1.Insert("Developers", p123);
    h1.Insert("Designers", p124);
    h1.Insert("Analysts", p125);



    h1.Insert("Economists", p1);
    h1.Insert("Coders", p2);
    h1.Insert("CEO", p3);
    h1.Insert("Coders", p4);
    h1.Insert("Economists", p5);
    h1.Insert("Bodyguard", p6);

    h1.DelRelease("Coders", 3);
    h1.Search("Coders");


    h1.PrintTable();


//
//    h1.DelKey("Coders");
//    h1.DelKey("Economists");


}
