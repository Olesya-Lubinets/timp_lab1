//
// Created by y2g on 04.02.2020.
//

#ifndef LAB1_TEXT_H
#define LAB1_TEXT_H
#include <string>
#include <iostream>
#include <fstream>
#include <locale>
#include <Windows.h>

namespace mLab {

    // Перечисление типов текста
    enum txt_type {
        REPLACEMENT = 1,
        CYCLE = 2
    };

    // Класс для объединения текстов
    class text {
    public:
        ~text();
        virtual void Init()=0;
        virtual void cipher()=0;
        virtual int read(std::ifstream*)=0;
        virtual std::string info_string()=0;
        text(){}
        txt_type get_type() {return type;}
        void set_type(int _type);
        void set_next(text *_next);

        text *get_next();

    protected:
        txt_type type;
        text *next;
    };

    // Вывод ошибки по коду error_code
    int print_err(int error_code);
    // Класс текста с заменами
    class txt_replacement : public text{
    public:
        void Init();

        ~txt_replacement();

        txt_replacement();

        std::string info_string();

        std::pair<char,char> *get_mapping();

        std::string *get_cipher_txt();

        std::string *get_open_txt();

        void cipher();

        int read(std::ifstream*);
    private:
        int alphabet_length;
        std::pair<char, char> *mapping;
        std::string *cipher_txt;
        std::string *open_txt;
    };

    // Класс текста со сдвигом
    class txt_cycle : public text{
    public:
        void Init();

        txt_cycle();

        std::string *get_cipher_txt();

        std::string *get_open_txt();

        void cipher();

        int read(std::ifstream*);

        std::string info_string();
    private:
        int shift;
        std::string *cipher_txt;
        std::string *open_txt;
    };



    // Контейнер - однонаправленный цикличный список
    class _mContainer {
    public:
        _mContainer();

        void write_to_file(std::ofstream *_ofstr);

        int read_from_file(std::ifstream *_ifstr);

        text *text_at(int pos);

        bool remove(text *_node);

        void append(text *_node);

    private:
        text *start;
        text *end;
    };

}
#endif //LAB1_TEXT_H
