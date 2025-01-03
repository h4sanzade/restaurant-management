#include <iostream>
#include <string>
using namespace std;

const int Max_Order_Count = 50;

string Order_ids[Max_Order_Count];
string Customer_names[Max_Order_Count];
string Order_names[Max_Order_Count];
double Order_prices[Max_Order_Count];

int Count_order = 0;

void Create_Order() {
    cout << "Enter Order id: ";
    cin >> Order_ids[Count_order];

    cout << "Enter customer name: ";
    cin >> Customer_names[Count_order];

    cout << "Enter Order name: ";
    cin >> Order_names[Count_order];

    cout << "Enter price of order: ";
    cin >> Order_prices[Count_order];
}

void Show_Order_Detail(int index) {
    cout << "_______________________________________________" << endl;
    cout << "Order name: " << Order_names[index] << endl;
    cout << "Order ID: " << Order_ids[index] << endl;
    cout << "Price of order: " << Order_prices[index] << endl;
    cout << "Customer name: " << Customer_names[index] << endl;
    cout << "_______________________________________________" << endl;
}

int ShowMenu() {
    cout << "1. Add order" << endl;
    cout << "2. Search order" << endl;
    cout << "3. Update order" << endl;
    cout << "4. Delete order" << endl;
    cout << "5. Display order" << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

void ShowOrders() {
    for (int i = 0; i < Count_order; i++) {
        Show_Order_Detail(i);
    }
}

void Add_Order() {
    if (Count_order < Max_Order_Count) {
        Create_Order();
        Count_order++;
    }
    else {
        cout << "Maximum order count reached!" << endl;
    }
}

int Search_Order(const string order_id) {
    for (int i = 0; i < Count_order; i++) {
        if (Order_ids[i] == order_id) {
            return i;
        }
    }
    return -1;
}

void Update_Order() {
    string search_id;
    cout << "Enter the Order ID to update: ";
    cin >> search_id;

    int index = Search_Order(search_id);
    if (index != -1) {
        cout << "Enter new Order name: ";
        cin >> Order_names[index];

        cout << "Enter new price of order: ";
        cin >> Order_prices[index];

        cout << "Enter new customer name: ";
        cin >> Customer_names[index];

        cout << "Order updated successfully!" << endl;
    }
    else {
        cout << "Order not found!" << endl;
    }
}

void Delete_Order() {
    string search_id;
    cout << "Enter the Order ID to delete: ";
    cin >> search_id;

    int index = Search_Order(search_id);
    if (index != -1) {
        for (int i = index; i < Count_order - 1; i++) {
            Order_ids[i] = Order_ids[i + 1];
            Customer_names[i] = Customer_names[i + 1];
            Order_names[i] = Order_names[i + 1];
            Order_prices[i] = Order_prices[i + 1];
        }
        Count_order--;
        cout << "Order deleted successfully!" << endl;
    }
    else {
        cout << "Order not found!" << endl;
    }
}

int main() {
    int choice;
    do {
        choice = ShowMenu();

        switch (choice) {
        case 1:
            Add_Order();
            break;
        case 2: {
            string search_id;
            cout << "Enter the Order ID to search: ";
            cin >> search_id;
            int index = Search_Order(search_id);
            if (index != -1) {
                Show_Order_Detail(index);
            }
            else {
                cout << "Order not found!" << endl;
            }
            break;
        }
        case 3:
            Update_Order();
            break;
        case 4:
            Delete_Order();
            break;
        case 5:
            ShowOrders();
            break;
        default:
            cout << "Wrong input!! ";
            break;
        }
    } while (choice != 5);

    return 0;
}
