#include <bits/stdc++.h>

class Contact {
private:
    std::string name;
    std::string phoneNumber;
    std::string emailAddress;

public:
    Contact(const std::string &name, const std::string &phoneNumber, const std::string &emailAddress)
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress) {}

    void displayContact() const {
        std::cout << "Name: " << name << "\nPhone Number: " << phoneNumber << "\nEmail Address: " << emailAddress << std::endl;
    }

    void editContact(const std::string &newName, const std::string &newPhoneNumber, const std::string &newEmailAddress) {
        name = newName;
        phoneNumber = newPhoneNumber;
        emailAddress = newEmailAddress;
    }

    std::string getName() const {
        return name;
    }
};

class ContactList {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &emailAddress) {
        contacts.emplace_back(name, phoneNumber, emailAddress);
        std::cout << "Contact added successfully!\n";
    }

    void displayContacts() const {
        if (contacts.empty()) {
            std::cout << "Contact list is empty.\n";
            return;
        }
        std::cout << "Contact List:\n";
        for (const auto &contact : contacts) {
            contact.displayContact();
            std::cout << "----------------\n";
        }
    }

    void editContact(const std::string &name) {
        for (auto &contact : contacts) {
            if (contact.getName() == name) {
                std::string newName, newPhoneNumber, newEmailAddress;
                std::cout << "Enter new name: ";
                std::cin >> newName;
                std::cout << "Enter new phone number: ";
                std::cin >> newPhoneNumber;
                std::cout << "Enter new email address: ";
                std::cin >> newEmailAddress;
                contact.editContact(newName, newPhoneNumber, newEmailAddress);
                std::cout << "Contact edited successfully!\n";
                return;
            }
        }
        std::cout << "Contact not found!\n";
    }

    void deleteContact(const std::string &name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact &contact) {
            return contact.getName() == name;
        });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Contact deleted successfully!\n";
        } else {
            std::cout << "Contact not found!\n";
        }
    }
};

int main() {
    ContactList contactList;
    std::string name, phoneNumber, emailAddress;

    while (true) {
        int choice;
        std::cout << "\nContact Management System\n";
        std::cout << "1. Add Contact\n2. Display Contacts\n3. Edit Contact\n4. Delete Contact\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter phone number: ";
                std::cin >> phoneNumber;
                std::cout << "Enter email address: ";
                std::cin >> emailAddress;
                contactList.addContact(name, phoneNumber, emailAddress);
                break;
            case 2:
                contactList.displayContacts();
                break;
            case 3:
                std::cout << "Enter name of contact to edit: ";
                std::cin >> name;
                contactList.editContact(name);
                break;
            case 4:
                std::cout << "Enter name of contact to delete: ";
                std::cin >> name;
                contactList.deleteContact(name);
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
