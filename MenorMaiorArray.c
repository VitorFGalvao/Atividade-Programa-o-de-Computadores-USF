#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 // Defina o número máximo de tarefas
#define MAX_STOCK_ITEMS 50 // Defina o número máximo de itens no estoque

// Estrutura para representar uma tarefa
struct Task {
    char description[100];
    int completed;
    char dueDate[20]; // Adicionar uma data de vencimento para a tarefa (formato de string)
    int priority;    // Adicionar um campo de prioridade para a tarefa
    double estimatedTime; // Adicionar o tempo estimado necessário para concluir a tarefa (em horas)
    char assignee[50];    // Adicionar um campo para o nome da pessoa responsável pela tarefa
};

// Estrutura para representar um item no estoque
struct StockItem {
    char name[100];
    int quantity;
    double price;
};

// Função para adicionar um novo item ao estoque
void addItemToStock(struct StockItem stock[], int *stockCount, char name[], int quantity, double price) {
    if (*stockCount < MAX_STOCK_ITEMS) {
        struct StockItem newItem;
        strcpy(newItem.name, name);
        newItem.quantity = quantity;
        newItem.price = price;
        stock[*stockCount] = newItem;
        (*stockCount)++;
        printf("Item adicionado ao estoque com sucesso.\n");
    } else {
        printf("O estoque está cheio.\n");
    }
}

// Função para listar todos os itens no estoque
void listStock(struct StockItem stock[], int stockCount) {
    if (stockCount == 0) {
        printf("O estoque está vazio.\n");
    } else {
        printf("Itens no estoque:\n");
        for (int i = 0; i < stockCount; i++) {
            printf("%d. %s - Quantidade: %d, Preço: %.2lf\n", i + 1, stock[i].name, stock[i].quantity, stock[i].price);
        }
    }
}

// Função para editar um item no estoque
void editStockItem(struct StockItem stock[], int stockCount, int itemIndex) {
    if (itemIndex >= 0 && itemIndex < stockCount) {
        struct StockItem *item = &stock[itemIndex];
        printf("Editando Item no Estoque %d:\n", itemIndex + 1);
        printf("Novo nome: ");
        scanf(" %[^\n]", item->name);
        printf("Nova quantidade: ");
        scanf("%d", &item->quantity);
        printf("Novo preço: ");
        scanf("%lf", &item->price);
        printf("Item no estoque editado com sucesso.\n");
    } else {
        printf("Índice de item no estoque inválido.\n");
    }
}

// Função para apagar um item do estoque
void deleteStockItem(struct StockItem stock[], int *stockCount, int itemIndex) {
    if (itemIndex >= 0 && itemIndex < *stockCount) {
        for (int i = itemIndex; i < *stockCount - 1; i++) {
            stock[i] = stock[i + 1];
        }
        (*stockCount)--;
        printf("Item no estoque apagado com sucesso.\n");
    } else {
        printf("Índice de item no estoque inválido.\n");
    }
}

// Função para adicionar uma nova tarefa à lista
void addTask(struct Task tasks[], int *taskCount, char description[], char dueDate[], int priority, double estimatedTime, char assignee[]) {
    if (*taskCount < MAX_TASKS) {
        struct Task newTask;
        strcpy(newTask.description, description);
        newTask.completed = 0; // Inicialmente, a tarefa não está completa
        strcpy(newTask.dueDate, dueDate);
        newTask.priority = priority;
        newTask.estimatedTime = estimatedTime;
        strcpy(newTask.assignee, assignee);
        tasks[*taskCount] = newTask;
        (*taskCount)++;
        printf("Tarefa adicionada com sucesso.\n");
    } else {
        printf("A lista de tarefas está cheia.\n");
    }
}

// Função principal
int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;

    struct StockItem stock[MAX_STOCK_ITEMS];
    int stockCount = 0;

    int choice;
    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Marcar tarefa como concluída\n");
        printf("4. Visualizar tarefa\n");
        printf("5. Editar tarefa\n");
        printf("6. Apagar uma tarefa\n");
        printf("7. Adicionar item ao estoque\n");
        printf("8. Listar itens no estoque\n");
        printf("9. Editar item no estoque\n");
        printf("10. Apagar item do estoque\n");
        printf("11. Apagar todas as tarefas\n");
        printf("12. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Código para adicionar tarefa
                break;
            case 2:
                // Código para listar tarefas
                break;
            case 3:
                // Código para marcar tarefa como concluída
                break;
            case 4:
                // Código para visualizar tarefa
                break;
            case 5:
                // Código para editar tarefa
                break;
            case 6:
                // Código para apagar uma tarefa
                break;
            case 7:
                printf("Digite o nome do item: ");
                char itemName[100];
                scanf(" %[^\n]", itemName);
                printf("Digite a quantidade do item: ");
                int itemQuantity;
                scanf("%d", &itemQuantity);
                printf("Digite o preço do item: ");
                double itemPrice;
                scanf("%lf", &itemPrice);
                addItemToStock(stock, &stockCount, itemName, itemQuantity, itemPrice);
                break;
            case 8:
                listStock(stock, stockCount);
                break;
            case 9:
                printf("Digite o índice do item no estoque a ser editado: ");
                int itemIndex;
                scanf("%d", &itemIndex);
                editStockItem(stock, stockCount, itemIndex - 1);
                break;
            case 10:
                printf("Digite o índice do item no estoque a ser apagado: ");
                int deleteIndex;
                scanf("%d", &deleteIndex);
                deleteStockItem(stock, &stockCount, deleteIndex - 1);
                break;
            case 11:
                // Código para apagar todas as tarefas
                break;
            case 12:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (choice != 12);

    return 0;
}

