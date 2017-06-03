#ifndef SAVEDDATABASES_HPP
#define SAVEDDATABASES_HPP

#include <QMap>
#include <QObject>
#include <QString>

class SavedDatabases
{
public:
	static QString getPath();

	static bool addDatabase(QString name, QMap<QString, QString> data);

	static QMap<QString, QMap<QString, QString>> getDatabases();
	static QMap<QString, QString> getDatabase(QString name);
};

#endif // SAVEDDATABASES_HPP
