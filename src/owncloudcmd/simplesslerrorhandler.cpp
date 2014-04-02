/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */
#include "mirall/mirallconfigfile.h"
#include "mirall/utility.h"
#include "mirall/account.h"
#include "simplesslerrorhandler.h"

#include <QtGui>
#include <QtNetwork>


bool SimpleSslErrorHandler::handleErrors(QList<QSslError> errors, QList<QSslCertificate> *certs, Account *account)
{
    (void) account;

    if (!certs) {
        qDebug() << "Certs parameter required but is NULL!";
        return false;
    }

    foreach( QSslError error, errors ) {
        certs->append( error.certificate() );
    }
    return true;
}
