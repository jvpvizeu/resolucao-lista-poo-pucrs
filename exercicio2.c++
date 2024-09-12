#include <iostream>

class Elevador {
private:
    int andarAtual;
    int totalAndares;
    int capacidade;
    int pessoasPresentes;

public:
    // Construtor vazio => Costuma ser uma boa prática de programacao, pois garante que o objeto seja iniciado com atributos adequados.
    Elevador() : andarAtual(0), totalAndares(0), capacidade(0), pessoasPresentes(0) {} // Garante que os atributos sejam iniciados em zero

    // Método para inicializar o elevador
    void inicializa(int capacidade, int totalAndares) {
        this->capacidade = capacidade;
        this->totalAndares = totalAndares;
        this->andarAtual = 0;         // Sempre começa no térreo
        this->pessoasPresentes = 0;   // Sempre começa vazio
    }

    // Método para entrar uma pessoa
    void entra() {
        if (pessoasPresentes < capacidade) {
            pessoasPresentes++;
            std::cout << "Uma pessoa entrou. Pessoas no elevador: " << pessoasPresentes << "\n";
        } else {
            std::cout << "Elevador cheio! Não pode entrar mais ninguém.\n";
        }
    }

    // Método para sair uma pessoa
    void sai() {
        if (pessoasPresentes > 0) {
            pessoasPresentes--;
            std::cout << "Uma pessoa saiu. Pessoas no elevador: " << pessoasPresentes << "\n";
        } else {
            std::cout << "Elevador vazio! Não há ninguém para sair.\n";
        }
    }

    // Método para subir um andar
    void sobe() {
        if (andarAtual < totalAndares) {
            andarAtual++;
            std::cout << "Subiu para o andar " << andarAtual << "\n";
        } else {
            std::cout << "Já está no último andar!\n";
        }
    }

    // Método para descer um andar
    void desce() {
        if (andarAtual > 0) {
            andarAtual--;
            std::cout << "Desceu para o andar " << andarAtual << "\n";
        } else {
            std::cout << "Já está no térreo!\n";
        }
    }

    // Métodos getters para obter os dados armazenados
    int getAndarAtual() const {
        return andarAtual;
    }

    int getTotalAndares() const {
        return totalAndares;
    }

    int getCapacidade() const {
        return capacidade;
    }

    int getPessoasPresentes() const {
        return pessoasPresentes;
    }
};

int main() {
    // Criando um objeto Elevador e inicializando com capacidade e total de andares
    Elevador elevador;
    elevador.inicializa(5, 10); // Capacidade de 5 pessoas e 10 andares

    // Simulando algumas operações
    elevador.entra();
    elevador.entra();
    elevador.sobe();
    elevador.sobe();
    elevador.desce();
    elevador.sai();
    elevador.sai();
    elevador.desce();

    // Exibindo o estado atual do elevador
    std::cout << "Andar atual: " << elevador.getAndarAtual() << "\n";
    std::cout << "Total de andares: " << elevador.getTotalAndares() << "\n";
    std::cout << "Capacidade do elevador: " << elevador.getCapacidade() << "\n";
    std::cout << "Pessoas presentes: " << elevador.getPessoasPresentes() << "\n";

    return 0;
}