/*
 * Copyright (C) 2004-2012 See the AUTHORS file for details.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */

#include <znc/Modules.h>
#include <znc/Chan.h>
#include <znc/User.h>
#include <znc/IRCNetwork.h>

class CNickHighlightAttach : public CModule {
public:
    MODCONSTRUCTOR(CNickHighlightAttach) {}
    ~CNickHighlightAttach() {}

    void CheckAttach(const CString& sMessage, CChan& Channel) {
        if (Channel.IsDetached()) {
            if (sMessage.AsLower().find(GetNetwork()->GetCurNick().AsLower()) != CString::npos) {
                Channel.JoinUser();
            }
        }
    }

    EModRet OnChanNotice(CNick& Nick, CChan& Channel, CString& sMessage) override {
        CheckAttach(sMessage, Channel);
        return CONTINUE;
    }

    EModRet OnChanMsg(CNick& Nick, CChan& Channel, CString& sMessage) override {
        CheckAttach(sMessage, Channel);
        return CONTINUE;
    }

    EModRet OnChanAction(CNick& Nick, CChan& Channel, CString& sMessage) override {
        CheckAttach(sMessage, Channel);
        return CONTINUE;
    }
};

MODULEDEFS(CNickHighlightAttach, "Reattaches you to a detached channel when someone mentions your nick in it.")
