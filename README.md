# Auto2030 SQL Management

**Autovermietung2030** is a comprehensive car management system developed using Qt and SQLite. This application is designed to manage customers, vehicles, and rental transactions through a graphical user interface.

## Features

- **Customer Management**:
  - View a list of all customers.
  - Add, edit, or remove individual customer entries.
  
- **Vehicle Management**:
  - View a list of all vehicles.
  - Add, edit, or remove individual vehicle entries.

- **Rental Management**:
  - Handle vehicle rentals and returns.
  - Make reservations for vehicles.

## How to Run

1. **Install [Qt](https://www.qt.io/download)** (if not already installed).
2. **Database Setup**:
   - A sample SQLite database file named `auto2030.db` is included in the repository for convenience. This allows you to test the application immediately.
   - Ensure this database file is in the same directory as the executable.
3. **Open the Project**:
   - Open the `autovermietung2030.pro` file in Qt Creator.
4. **Build and Run**:
   - Build and run the project within Qt Creator.

## Technologies Used

- **C++**: Core language for application logic.
- **Qt**: Used for GUI elements (QMainWindow, QPushButton, QLabel, QTimer).
- **SQLite**: Database for managing customers, vehicles, and rentals.
- **QSqlDatabase**: For handling the SQLite database connection.
- **QSqlQuery**: For executing SQL queries.

## Comments

Please note that all comments in the source code are written in German.

---

# Auto2030 SQL Management

**Autovermietung2030** ist ein umfassendes Fahrzeugverwaltungssystem, das mit Qt und SQLite entwickelt wurde. Diese Anwendung ist darauf ausgelegt, Kunden, Fahrzeuge und Miettransaktionen über eine grafische Benutzeroberfläche zu verwalten.

## Funktionen

- **Kundenverwaltung**:
  - Anzeige einer Liste aller Kunden.
  - Hinzufügen, Bearbeiten oder Entfernen einzelner Kundeneinträge.
  
- **Fahrzeugverwaltung**:
  - Anzeige einer Liste aller Fahrzeuge.
  - Hinzufügen, Bearbeiten oder Entfernen einzelner Fahrzeugeinträge.

- **Mietverwaltung**:
  - Verwaltung von Fahrzeugmieten und -rückgaben.
  - Reservierungen von Fahrzeugen vornehmen.

## So führen Sie das Programm aus

1. **Installieren Sie [Qt](https://www.qt.io/download)** (falls noch nicht installiert).
2. **Datenbankeinrichtung**:
   - Eine Beispiel-SQLite-Datenbankdatei namens `auto2030.db` ist zur Bequemlichkeit im Repository enthalten. Dies ermöglicht es Ihnen, die Anwendung sofort zu testen.
   - Stellen Sie sicher, dass sich diese Datenbankdatei im selben Verzeichnis wie die ausführbare Datei befindet.
3. **Projekt öffnen**:
   - Öffnen Sie die Datei `autovermietung2030.pro` in Qt Creator.
4. **Build und Ausführen**:
   - Erstellen und führen Sie das Projekt innerhalb von Qt Creator aus.

## Verwendete Technologien

- **C++**: Hauptsprache für die Anwendungslogik.
- **Qt**: Wird für GUI-Elemente (QMainWindow, QPushButton, QLabel, QTimer) verwendet.
- **SQLite**: Datenbank zur Verwaltung von Kunden, Fahrzeugen und Mietvorgängen.
- **QSqlDatabase**: Zum Umgang mit der SQLite-Datenbankverbindung.
- **QSqlQuery**: Zum Ausführen von SQL-Abfragen.
