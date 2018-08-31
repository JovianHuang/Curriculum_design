#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

void DisplayWelcome(void);

void DisplayFirstLevelMenu(void);

void DisplayTheSearchMenu(void);

bool YesOrNo(void);

InfoNode * EnsureDeleteInfo(InfoNode * head);

InfoNode * EnsureModifyInfo(InfoNode * head);

#endif // !USERFUNCTIONS_H

