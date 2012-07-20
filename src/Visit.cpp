#include "Visit.h"
#include "SocketCommand.h"
#include "WebPage.h"
#include "WebPageManager.h"

Visit::Visit(WebPageManager *manager, QStringList &arguments, QObject *parent) : SocketCommand(manager, arguments, parent) {
}

void Visit::start() {
  QString urlString = QString(arguments()[0].toUtf8());
  QUrl requestedUrl = QUrl(urlString, QUrl::StrictMode);
  page()->currentFrame()->load(requestedUrl);
  emit finished(new Response(true));
}
