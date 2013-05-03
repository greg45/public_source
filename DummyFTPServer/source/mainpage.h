/***************************************************************************
 *   Copyright (C) 2010 by Marek Hakala   *
 *   marek@hakala.cz   *
 *
 *   Semestrální práce PA2 - ČVUT FIT
 *   Téma : Implementace FTP serveru
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*! \mainpage Projekt FTP server
 *  \author Marek Hakala <marek@hakala.cz>
 *  \version 1.0.0-unstable
    \date 2010
 *  \section oprojektu DummyFTPServer
 *
 * Toto je semestrální práce do předmětu BI-PA2 na FIT ČVUT.
 *
 * \image html dfsd.png
 *
 * \subsection zadani Zadání
 *
 * Program bude sloužit k přenosu souboru prostřednictvím protokolu FTP (File Transfer Protocol).
 * Určitě stojí za to zmínit, že program bude používat sítovou architekturu klient-server. Aplikace po
 * startu provede načtení konfiguračního souboru. Na základě konfigurace začne program poslouchat
 * na daném TCP portu a soketu. Jakmile se připojí k serveru klient bude vytvořeno speciální vlákno v
 * rámci, kterého s ním bude komunikováno. Prvním krokem bude autorizační mechanismus, který
 * provede ověření uživatelského jména a hesla oproti speciálnímu souboru. Po řádné autorizaci bude
 * uživateli zpřístupněn obsah domovského adresáře a bude mít možnost obousměrného přenosu souborů.
 *
 * Aplikace nebude obsahovat kompletní implementaci FTP protokolu podle normy RFC959 ale pouze
 * nezbytnou část pro úplně základní operace. A to s časových důvodů.
 *
 * Program bude pracovat v textovém módu. Informace o běhu ftp serveru budou vypisovány na standardním výstupu.
 * Program bude možné vypnout stisknutím klávesy „CTRL + C“.
 *
 * \subsection autorizace Autorizace
 * Vzdálený klient bude vyzván k zaslání uživatelského jména a hesla. Údaje budou
 * porovnaný s údaji ve speciálním souboru, sloužícímu k autorizaci. Jeden řádek odpovídá jednomu záznamu.
 *
 * \subsection prenos_souboru Přenos souboru
 *  Uživatel si vyžádá soubor, který mu bude binárně zaslán prostřednictvím tcp soketu.
 *  V opačném směru bude klient vyzván k zaslání obsahu souboru prostřednictvím tcp soketu.
 * Obsah bude převzat a uložen do nově vzniklého souboru na straně serveru.
 *
 * \subsection nastaveni Nastavení
 * Primárně bude využit konfigurační soubor. Ale některé věci bude možné změnit pomoci vstupních
 * argumentů. V konfiguračním souboru uživatel nalezne proměnné port, anonymous a anonymousPath
 * pomocí, kterých budete moct změnit nastavení.
 *
 * \subsection Screenshot
 * \image html dfsd-usage.png
 *
 * \subsubsection Technologie
 * \image html qt.png
 */
