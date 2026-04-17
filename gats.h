#ifndef GATS_H
#define GATS_H

#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>

class UserManager
{
public:
    UserManager() {
        loadUsers();
    }

    bool registerUser(const QString &login, const QString &password) {
        if (users.contains(login)) {
            return false;
        }

        users[login] = password;
        saveUserToFile(login, password);
        return true;
    }

    bool checkUser(const QString &login, const QString &password) {
        return users.contains(login) && users[login] == password;
    }

private:
    QMap<QString, QString> users;

    void loadUsers() {
        QFile file("users.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(":");
            if (parts.size() == 2) {
                users[parts[0]] = parts[1];
            }
        }
        file.close();
    }

    void saveUserToFile(const QString &login, const QString &password) {
        QFile file("users.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << login << ":" << password << "\n";
            file.close();
        }
    }
};


#endif // GATS_H
