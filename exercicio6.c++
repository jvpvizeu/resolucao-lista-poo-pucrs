#include <iostream>

class Televisao {
private:
    int volume;
    int canal;

public:
    // Construtor: Inicializa a TV com volume 10 e canal 1
    Televisao() : volume(10), canal(1) {}

    // Método para aumentar o volume em uma unidade (máximo de 100)
    void aumentarVolume() {
        if (volume < 100) {
            volume++;
        } else {
            std::cout << "Volume já está no máximo!" << std::endl;
        }
    }

    // Método para diminuir o volume em uma unidade (mínimo de 0)
    void diminuirVolume() {
        if (volume > 0) {
            volume--;
        } else {
            std::cout << "Volume já está no mínimo!" << std::endl;
        }
    }

    // Método para aumentar o canal em uma unidade
    void aumentarCanal() {
        canal++;
    }

    // Método para diminuir o canal em uma unidade (mínimo de 1)
    void diminuirCanal() {
        if (canal > 1) {
            canal--;
        } else {
            std::cout << "Já está no menor canal possível!" << std::endl;
        }
    }

    // Método para trocar para um canal específico
    void trocarCanal(int novoCanal) {
        if (novoCanal > 0) {
            canal = novoCanal;
        } else {
            std::cout << "Canal inválido!" << std::endl;
        }
    }

    // Método para consultar o valor atual do volume
    int consultarVolume() const {
        return volume;
    }

    // Método para consultar o canal atual
    int consultarCanal() const {
        return canal;
    }
};

int main() {
    Televisao tv;

    // Aumentando o volume 3 vezes
    tv.aumentarVolume();
    tv.aumentarVolume();
    tv.aumentarVolume();

    // Mudando de canal: aumentar 2 vezes e trocar para o canal 45
    tv.aumentarCanal();
    tv.aumentarCanal();
    tv.trocarCanal(45);

    // Diminuindo o canal 1 vez
    tv.diminuirCanal();

    // Exibindo o volume e o canal atuais
    std::cout << "Volume atual: " << tv.consultarVolume() << std::endl;
    std::cout << "Canal atual: " << tv.consultarCanal() << std::endl;

    return 0;
}
