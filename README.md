# cpp_education
This repo is created for sharing my C++ code with my fellow students and teachers.

## C++ environment
Весь C++ код компилируется в Linux (Ubuntu 24.04) компилятором GNU (g++). Иногда применяются специфичные для этого компилятора пРИкОлЫ, например задание размера массива переменной, а не константой.

### Как организовать?
Обзаведитесь машиной на [Ubuntu Desktop](https://ubuntu.com/desktop) (для базовичков), [Ubuntu Server](https://ubuntu.com/server) (для БАЗИРОВАННЫХ), [Kubuntu](https://kubuntu.org/) (оно красивое), [Debian](https://www.debian.org/index.ru.html) (уважаю) или любом другом APT дистрибутиве (а если вы любитель RPM - это ваше дело). Можете воспользоваться [WSL на Windows](https://learn.microsoft.com/ru-ru/windows/wsl/install) или развернуть виртуальную машину на [Hyper-V](https://learn.microsoft.com/ru-ru/windows-server/virtualization/hyper-v/get-started/install-hyper-v?tabs=powershell&pivots=windows), [VirtualBox](https://www.virtualbox.org/) (наиболее простой вариант), [VMWare](https://www.vmware.com/) или даже [KVM](https://linux-kvm.org/page/Documents), хотя, если вы используете KVM, это всё вам читать уже не нужно.

Установите g++ и git:
```bash
sudo apt install git g++ -y
```
Склонируйте репозиторий:
```bash
git clone https://github.com/BexaGal/cpp_education.git
```
Далее вы можете зайти в любую директорию с кодом и скомпилировать нужный файл:
```bash
g++ ./lalala.cpp
```
И запустить исполняемый файл:
```bash
./a.out
```
Если файл не исполняется, добавьте ему разрешение на исполнение:
```bash
chmod +x ./a.out
```
Всё.

### Полная виндовая установка
На если вы не хотите иметь дело с Linux или очень любите Windows, да так, что аж не можете терпеть виртуалки с Linux, можете воспользоваться [git для windows](https://git-scm.com/install/windows) и набором компиляторов для Windows от MinGW, рекомендую вариант установки через [Cygwin](https://cygwin.com/install.html).

После установки в любом командном интерпретаторе (cmd.exe или PowerShell) будет доступен g++. А git будет доступен через GitBash. В остальном инстукции совпадают с вышеописанными, за исключением того, что исполняемые файлы будут не .out формата, а .exe.

### Microsoft Visual Studio
В комплекте IDE от Microsoft [Visual Studio](https://visualstudio.microsoft.com/ru/) можно поставить компилятор C++. Этот компилятор рабочий, но я не гарантирую сборку моего кода на ней. Весь мой код пишется под GNU C++ Compiler.

## Особеннсоти данной репы
В репозиторий нельзя пушить, но вы можете сделать свой форк от неё.
