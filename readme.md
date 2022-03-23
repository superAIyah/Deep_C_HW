*by: Fedor Safonov*

*My 1 Homework C/C++*

## Чтобы запустить проект на локальной машине:
1. Скачать необходимые библиотеки
```
sudo apt update -y
sudo apt install -y cppcheck clang-tidy python3-pip libc6-dbg cmake libgtest-dev
sudo pip install cpplint
```
* Для запуска тестов выполнить из директории проекта:
```
make test
```
* Для запуска линтеров выполнить из директории проекта:
```
make check
```
