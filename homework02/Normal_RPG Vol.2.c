#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    int health;
    int attack;
} Character;

typedef struct {
    Character player;
    Character monster;
} GameData;

typedef enum {
    Weapon_Sword,
    Weapon_Bow,
    Weapon_Staff
} Weapon;

typedef enum {
    Skill_Fireball,
    Skill_IceBlast,
    Skill_ThunderStrike,
    Skill_PoisonArrow,
    Skill_LightningBolt,
    Skill_Heal
} Skill;

void initialize(GameData* game) {
    game->player.health = 100;
    game->player.attack = 10;

    game->monster.health = 105;
    game->monster.attack = 8;
}

int getPlayerDamage(Character* player, Weapon weapon) {
    int baseDamage = player->attack;
    int randomModifier = rand() % 6;  // Add some randomness to the damage

    switch (weapon) {
    case Weapon_Sword:
        baseDamage += 5;
        break;
    case Weapon_Bow:
        baseDamage += 3;
        break;
    case Weapon_Staff:
        baseDamage += 2;
        break;
    default:
        break;
    }

    return baseDamage + randomModifier;
}

int getPlayerSkillDamage(Skill skill) {
    switch (skill) {
    case Skill_Fireball:
        return 15;
    case Skill_IceBlast:
        return 12;
    case Skill_ThunderStrike:
        return 18;
    case Skill_PoisonArrow:
        return 10;
    case Skill_LightningBolt:
        return 20;
    case Skill_Heal:
        return -15;  // Negative value to represent healing
    default:
        return 0;
    }
}

void playerAttack(GameData* game, Weapon weapon) {
    int damage = getPlayerDamage(&game->player, weapon);
    game->monster.health -= damage;
    printf("당신은 무기로 몬스터를 공격하여 %d의 데미지를 입혔습니다!\n", damage);

    // Monster animation
    printf("몬스터가 피해를 입었습니다!\n");
    printf("\n");

    printf("몬스터가 공격을 맞았습니다!\n");
    Sleep(1000);  // 1초 동안 애니메이션 표시
    system("cls");
}


void playerUseSkill(GameData* game, Skill skill, Weapon weapon) {
    int damage = getPlayerSkillDamage(skill);

    switch (skill) {
    case Skill_Fireball:
        printf("파이어볼을 사용하여 몬스터에게 %d의 데미지를 입혔습니다!\n", damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    case Skill_IceBlast:
        printf("아이스 블래스트를 사용하여 몬스터에게 %d의 데미지를 입혔습니다!\n", damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    case Skill_ThunderStrike:
        printf("썬더 스트라이크를 사용하여 몬스터에게 %d의 데미지를 입혔습니다!\n", damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    case Skill_PoisonArrow:
        printf("독화살을 발사하여 몬스터에게 %d의 데미지를 입혔습니다!\n", damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    case Skill_LightningBolt:
        printf("번개 벼락을 소환하여 몬스터에게 %d의 데미지를 입혔습니다!\n", damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    case Skill_Heal:
        printf("힐 스킬을 사용하여 %d의 체력을 회복했습니다!\n", -damage);
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        break;
    default:
        break;
    }

    if (skill != Skill_Heal) {
        game->monster.health -= damage;
    }
    else {
        game->player.health -= damage;
    }

    // Monster animation
    if (damage > 0) {
        printf("몬스터가 피해를 입었습니다!\n");    
        printf("\n");
    }
    else if (damage < 0) {
        printf("몬스터가 회복되었습니다!\n");
        Sleep(1000);  // 1초 동안 애니메이션 표시
        system("cls");
        printf("\n");
    }
}

void monsterAttack(GameData* game) {
    int damage = game->monster.attack;
    game->player.health -= damage;
    printf("몬스터가 당신을 공격하여 %d의 데미지를 입혔습니다!\n", damage);

    // Player animation
    printf("플레이어가 피해를 입었습니다!\n");
    printf("\n");
}

void displayStats(GameData* game) {
    system("cls"); // Clear the screen to display a new screen

    printf("=========== 야생의 몬스터가 나타났습니다!! ===========\n\n");

    printf("플레이어 체력: ");
    for (int i = 0; i < game->player.health; i++) {
        printf("=");
    }
    printf("\n");

    printf("몬스터 체력: ");
    for (int i = 0; i < game->monster.health; i++) {
        printf("=");
    }
    printf("\n");

    printf("\n");

    // Monster ASCII art
    printf("              __,='`````'=/__\n");
    printf("             '//  (o) \\(o)  \\ `'         _,-,\n");
    printf("             //|     ,_)   (`\\      ,-'`_,-\\,\n");
    printf("           ,-~~~\\  `'==='  /-,      \\==```` \\__\n");
    printf("          /        `----'     `\\     \\       \\/\n");
    printf("       ,-`                  ,   \\  ,.-\\       \\\n");
    printf("      /      ,               \\,-`\\`_,-` \\       \\\n");
    printf("     ,`    ,/,              ,>,   )     \\,-'\\     /\n");
    printf("     (      `\\`---'`  `-,-'`_,<   \\      \\__\\,--'` \n");
    printf("      `.      `--. _,-'`_,-`  |    \\\n");
    printf("        `              `       `    \\\n\n");
}

void showTitleScreen() {
    printf("==============================================\n");
    printf("=                                            =\n");
    printf("=                                            =\n");
    printf("=                                            =\n");
    printf("=             일반적인 RPG 게임              =\n");
    printf("=                                            =\n");
    printf("=                                            =\n");
    printf("=                                            =\n");
    printf("==============================================\n");
    printf("\n");
}

int main() {
    GameData game;
    srand(time(NULL));

    initialize(&game);

    showTitleScreen();

    printf("======= 무기를 선택하세요 =======\n");
    printf("=                               =\n");
    printf("=           1. 검               =\n");
    printf("=           2. 활               =\n");
    printf("=           3. 지팡이           =\n");
    printf("=                               =\n");
    printf("=================================\n");

    int weaponChoice;
    if (scanf_s("%d", &weaponChoice) != 1) {
        printf("잘못된 입력입니다! 기본 무기(검)를 사용합니다.\n");
        weaponChoice = 1;
    }

    Weapon weapon;
    switch (weaponChoice) {
    case 1:
        weapon = Weapon_Sword;
        break;
    case 2:
        weapon = Weapon_Bow;
        break;
    case 3:
        weapon = Weapon_Staff;
        break;
    default:
        weapon = Weapon_Sword;
        break;
    }

    int gameOver = 0;
    while (!gameOver) {
        displayStats(&game);

        printf("======= 액션을 선택하세요 =======\n");
        printf("=                               =\n");
        printf("=           1. 공격             =\n");
        printf("=           2. 스킬             =\n");
        printf("=           3. 도망가기         =\n");
        printf("=                               =\n");
        printf("=================================\n");

        int choice;
        if (scanf_s("%d", &choice) != 1) {
            printf("잘못된 입력입니다! 기본 액션(공격)을 수행합니다.\n");
            choice = 1;
        }

        switch (choice) {
        case 1:
            playerAttack(&game, weapon);
            monsterAttack(&game);
            break;
        case 2:
            printf("======= 스킬을 선택하세요 =======\n");
            printf("=                               =\n");
            printf("=         1. 파이어볼           =\n");
            printf("=         2. 아이스 블래스트    =\n");
            printf("=         3. 썬더 스트라이크    =\n");
            printf("=         4. 독화살             =\n");
            printf("=         5. 번개 벼락          =\n");
            printf("=         6. 힐 스킬            =\n");
            printf("=                               =\n");
            printf("=================================\n");

            int skillChoice;
            if (scanf_s("%d", &skillChoice) != 1) {
                printf("잘못된 입력입니다! 기본 스킬(파이어볼)을 사용합니다.\n");
                skillChoice = 1;
            }

            Skill skill;
            switch (skillChoice) {
            case 1:
                skill = Skill_Fireball;
                break;
            case 2:
                skill = Skill_IceBlast;
                break;
            case 3:
                skill = Skill_ThunderStrike;
                break;
            case 4:
                skill = Skill_PoisonArrow;
                break;
            case 5:
                skill = Skill_LightningBolt;
                break;
            case 6:
                skill = Skill_Heal;
                break;
            default:
                skill = Skill_Fireball;
                break;
            }

            playerUseSkill(&game, skill, weapon);
            monsterAttack(&game);
            break;
        case 3:
            printf("당신은 도망쳤습니다!\n");
            gameOver = 1;
            break;
        default:
            printf("잘못된 입력입니다! 기본 액션(공격)을 수행합니다.\n");
            playerAttack(&game, weapon);
            monsterAttack(&game);
            break;
        }

        if (game.player.health <= 0) {
            displayStats(&game);
            printf("당신은 사망하였습니다. 게임 오버!\n");
            gameOver = 1;
        }
        else if (game.monster.health <= 0) {
            displayStats(&game);
            printf("몬스터를 물리쳤습니다. 게임 클리어!\n");
            gameOver = 1;
        }
    }

    return 0;
}
