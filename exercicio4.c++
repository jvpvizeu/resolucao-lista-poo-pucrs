#include <iostream>

class Relogio {
private:
    int hora;
    int minuto;
    int segundo;

public:
    // Construtor vazio, inicializando com 00:00:00
    Relogio() : hora(0), minuto(0), segundo(0) {}

    // Método para configurar o horário (setHora)
    void setHora(int h, int m, int s) {
        if (h >= 0 && h < 24) {
            hora = h;
        } else {
            hora = 0;  // Hora inválida, define como 0
        }
        
        if (m >= 0 && m < 60) {
            minuto = m;
        } else {
            minuto = 0;  // Minuto inválido, define como 0
        }
        
        if (s >= 0 && s < 60) {
            segundo = s;
        } else {
            segundo = 0;  // Segundo inválido, define como 0
        }
    }

    // Método para obter o horário atual (getHora)
    void getHora(int &h, int &m, int &s) const {
        h = hora;
        m = minuto;
        s = segundo;
    }

    // Método para avançar o horário em um segundo (avança segundo)
    void avancarSegundo() {
        segundo++;
        if (segundo >= 60) {
            segundo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                hora++;
                if (hora >= 24) {
                    hora = 0;  // Avança para meia-noite
                }
            }
        }
    }

    // Método opcional para imprimir o horário no formato HH:MM:SS
    void imprimirHora() const {
        std::cout << (hora < 10 ? "0" : "") << hora << ":"
                  << (minuto < 10 ? "0" : "") << minuto << ":"
                  << (segundo < 10 ? "0" : "") << segundo << std::endl;
    }
};

int main() {
    Relogio relogio;
    
    // Configurando a hora para 23:59:58
    relogio.setHora(23, 59, 58);
    std::cout << "Horário atual: ";
    relogio.imprimirHora();

    // Avançando um segundo
    relogio.avancarSegundo();
    std::cout << "Após avançar um segundo: ";
    relogio.imprimirHora();

    // Avançando mais um segundo (deve ir para 00:00:00)
    relogio.avancarSegundo();
    std::cout << "Após avançar mais um segundo: ";
    relogio.imprimirHora();

    // Usando o método getHora para recuperar os valores individuais
    int h, m, s;
    relogio.getHora(h, m, s);
    std::cout << "Horário obtido: " << h << ":" << m << ":" << s << std::endl;

    return 0;
}
