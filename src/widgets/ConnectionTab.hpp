#ifndef CONNECTIONTAB_HPP
#define CONNECTIONTAB_HPP

#include <QMap>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QString>
#include <QWidget>

#include "src/types/Connection.hpp"

namespace Ui {
	class ConnectionTab;
}

class ConnectionTab : public QWidget
{
	Q_OBJECT
	
public:
	explicit ConnectionTab(QWidget* parent = 0);
	
	void setConnectionData(Connection* connection);
	void loadDatabases();
	
	bool canConnect();
	QString getError();
	
	void finish();

	void reload() { goPage(1); }

	QSqlDatabase getQSqlDatabase() { return db; }
	
	~ConnectionTab();
	
private:
	Ui::ConnectionTab* ui;
	Connection* connectionData;
	QSqlDatabase db;
	QString databaseName, tableName, driver;
	
	void requestPassword();
	void handleError();

	QVariant getValue(int row, int column, bool set = true);
	
signals:
	void finished();
	
public slots:
	void loadTables(QModelIndex index);
	void openTable(QModelIndex index);
	void changeValue(int row, int column);
	void setPassword(QString password, bool save);
	void open(int code);
	void handleType(int row, int column);
	void handleType(int row, int column, QVariant type);
	void editFinished(QString data);
	void goPage(int page);
	void insertRow();
	void doInsert(QList<QPair<QString, QVariant>>* data);
};

#endif // DATABASETAB_HPP
