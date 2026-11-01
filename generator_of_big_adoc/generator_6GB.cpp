#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // text we will repeat many times
    string text = "= Огромный заголовок\n\nЭто обычный абзац текста для теста.\n\n* Пункт списка 1\n* Пункт списка 2\n\n";

    // 6 GB = 6 * 1024 * 1024 * 1024 bytes
    unsigned long long targetSize = 6ULL * 1024 * 1024 * 1024;
    unsigned long long currentSize = 0;

    // always write into lab2 folder, no matter where you run from
    ofstream out("/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab2/big.adoc", ios::binary);
    if (!out) {
        cout << "Не удалось создать файл!" << endl;
        return 1;
    }

    cout << "Генерация файла... Пожалуйста, подождите." << endl;
    while (currentSize < targetSize) {
        out.write(text.c_str(), text.size());
        currentSize += text.size();
    }

    out.close();
    cout << "Готово! Файл big.adoc размером 6 ГБ создан." << endl;
    return 0;
}