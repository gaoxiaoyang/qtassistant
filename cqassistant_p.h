#ifndef CQASSISTANT_P_H
#define CQASSISTANT_P_H

#include "cqassistant.h"

class MasterLevels;
class MemberWelcome;
class MemberBlacklist;
class MemberDeathHouse;

#include "htmlfeedback/htmlfeedback.h"

class CqAssistantPrivate : public QObject, public CqEncoder
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(CqAssistant)

public:
    CqAssistantPrivate();
    virtual ~CqAssistantPrivate();
private:
    CqAssistant *q_ptr;

private:
    void initThread();
    void initialize();
private:
    QThread *agent;
    qint32   token;

private:
    qint64 currentId;
    QString basePath;

private:
    MasterLevels *levels;
    MemberWelcome *welcome;
    MemberBlacklist *blacklist;
    MemberDeathHouse *deathHouse;

private:
    void timerEvent(QTimerEvent *) Q_DECL_FINAL;

private:
    void groupHelp(const MessageEvent &ev, const QStringList &args);
    void groupLevel(const MessageEvent &ev, const QStringList &args);
    void groupRename(const MessageEvent &ev, const QStringList &args);

    void groupBan(const MessageEvent &ev, const QStringList &args);
    void groupKill(const MessageEvent &ev, const QStringList &args);
    void groupPower(const MessageEvent &ev, const QStringList &args);

    void groupUnban(const MessageEvent &ev, const QStringList &args);
    void groupUnkill(const MessageEvent &ev, const QStringList &args);
    void groupUnpower(const MessageEvent &ev, const QStringList &args);

    void groupWelcome(const MessageEvent &ev, const QStringList &args);
    void groupBlacklist(const MessageEvent &ev, const QStringList &args);

private:
    void permissionDenied(qint64 gid, qint64 uid, MasterLevel level, const QString &reason = QString());

    void showPrimaryList(qint64 gid, const QString &title, const LevelInfoList &members, bool level);
    void showDangerList(qint64 gid, const QString &title, const LevelInfoList &members, bool level);
    void showWarningList(qint64 gid, const QString &title, const LevelInfoList &members, bool level);
    void showPromptList(qint64 gid, const QString &title, const LevelInfoList &members, bool level);
    void showSuccessList(qint64 gid, const QString &title, const LevelInfoList &members, bool level);

    void feedbackList(qint64 gid, const QString &title, const LevelInfoList &members, bool level, HtmlFeedback::Style style);

private:
    HtmlFeedback *htmlFeedback;
    QString imagePath;
};

#endif // CQASSISTANT_P_H
