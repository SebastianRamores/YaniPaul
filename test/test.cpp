#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // Player starting stats
    int playerHp = 40;
    int playerAtk = 12;
    int playerDef = 5;

    // Boss stats
    int bossHp = 400;
    int bossAtk = 21;
    int bossDef = 20;

    // Item flags
    bool hasRapier = false;
    bool hasNet = false;
    bool hasSunglasses = false;
    bool hasAmulet = false;
    bool hasRustbite = false;

    // Scene 0: Introduction
    cout << "This is a fan-made educational project based on Bleach by Tite Kubo." << endl;
    cout << "All rights belong to their respective owners." << endl;
    cout << "This project is for non-commercial classroom use only." << endl << endl;

    // Scene 1: Prologue
    cout << "Scene 1: You are Jun Arashi, a young soul in District 67 of Rukongai." << endl;
    cout << "Life is harsh here, and tonight, a rogue Hollow named Bjorne attacks." << endl;
    cout << "You refuse to run and prepare to face the monster." << endl << endl;

    // Scene 2: The Saint
    cout << "Scene 2: You encounter Hanae the Saint, who offers spiritual blessings." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Receive a minor blessing (+4 ATK)" << endl;
    cout << "2. Mid: Balanced blessing (+1 ATK, +1 DEF, +7 HP)" << endl;
    cout << "3. Risky: Powerful blessing (+11 ATK, +3 DEF, -5 HP)" << endl;

    int choice2;
    cin >> choice2;
    if (choice2 == 1) {
        playerAtk += 4;
        cout << "You receive +4 ATK." << endl;
    } else if (choice2 == 2) {
        playerAtk += 1;
        playerDef += 1;
        playerHp += 7;
        cout << "You receive +1 ATK, +1 DEF, +7 HP." << endl;
    } else if (choice2 == 3) {
        playerAtk += 11;
        playerDef += 3;
        playerHp -= 5;
        cout << "You receive +11 ATK, +3 DEF, but lose 5 HP." << endl;
    } else {
        playerAtk += 4;
        cout << "Invalid choice. You receive +4 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 3: The Tinkerer
    cout << "Scene 3: Riku the Tinkerer offers you gadgets from his workshop." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Simple tool (+4 ATK)" << endl;
    cout << "2. Mid: Defensive gadget (+1 DEF, -2 HP)" << endl;
    cout << "3. Risky: Advanced device (+5 ATK, +3 DEF, -5 HP, gain Rustbite)" << endl;

    int choice3;
    cin >> choice3;
    if (choice3 == 1) {
        playerAtk += 4;
        cout << "You receive +4 ATK." << endl;
    } else if (choice3 == 2) {
        playerDef += 1;
        playerHp -= 2;
        cout << "You receive +1 DEF, but lose 2 HP." << endl;
    } else if (choice3 == 3) {
        playerAtk += 5;
        playerDef += 3;
        playerHp -= 5;
        hasRustbite = true;
        cout << "You receive +5 ATK, +3 DEF, -5 HP, and gain Rustbite (-6 Boss DEF)." << endl;
    } else {
        playerAtk += 4;
        cout << "Invalid choice. You receive +4 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 4: Sister Midori
    cout << "Scene 4: At the shrine, Sister Midori offers protective rites." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Basic rite (+4 ATK)" << endl;
    cout << "2. Mid: Protective net (gain Net to skip 1 boss attack, -2 HP)" << endl;
    cout << "3. Risky: Intense rite (+9 ATK, -4 HP)" << endl;

    int choice4;
    cin >> choice4;
    if (choice4 == 1) {
        playerAtk += 4;
        cout << "You receive +4 ATK." << endl;
    } else if (choice4 == 2) {
        hasNet = true;
        playerHp -= 2;
        cout << "You gain the Net, but lose 2 HP." << endl;
    } else if (choice4 == 3) {
        playerAtk += 9;
        playerHp -= 4;
        cout << "You receive +9 ATK, but lose 4 HP." << endl;
    } else {
        playerAtk += 4;
        cout << "Invalid choice. You receive +4 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 5: Yumi the Smuggler
    cout << "Scene 5: Yumi the Smuggler offers rare items." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Basic weapon (+11 ATK)" << endl;
    cout << "2. Mid: Armlet of Mordiggan (+15 ATK, -1 DEF, -2 HP)" << endl;
    cout << "3. Risky: Divine Rapier (275 true damage, one use, -10 HP, -3 DEF, -3 ATK)" << endl;

    int choice5;
    cin >> choice5;

    if (choice5 == 1) {
        playerAtk += 11;
        cout << "You receive +11 ATK." << endl;
    } else if (choice5 == 2) {
        playerAtk += 15;
        playerDef -= 1;
        playerHp -= 2;
        cout << "You equip the Armlet: +15 ATK, -1 DEF, -2 HP." << endl;
    } else if (choice5 == 3) {
        hasRapier = true;
        playerHp -= 10;
        playerDef -= 3;
        playerAtk -= 3;
        cout << "You gain Divine Rapier, but suffer -10 HP, -3 DEF, -3 ATK." << endl;
    } else {
        playerAtk += 11;
        cout << "Invalid choice. You receive +11 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 6: Kaji the Peddler
    cout << "Scene 6: Kaji the Peddler hawks his wares." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Common blade (+4 ATK)" << endl;
    cout << "2. Mid: Sharpened edge (+8 ATK, -2 HP)" << endl;
    cout << "3. Risky: Masterwork blade (+15 ATK, -2 DEF, -5 HP)" << endl;

    int choice6;
    cin >> choice6;

    if (choice6 == 1) {
        playerAtk += 4;
        cout << "You receive +4 ATK." << endl;
    } else if (choice6 == 2) {
        playerAtk += 8;
        playerHp -= 2;
        cout << "You receive +8 ATK, but lose 2 HP." << endl;
    } else if (choice6 == 3) {
        playerAtk += 15;
        playerDef -= 2;
        playerHp -= 5;
        cout << "You receive +15 ATK, -2 DEF, -5 HP." << endl;
    } else {
        playerAtk += 4;
        cout << "Invalid choice. You receive +4 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 7: Aiko
    cout << "Scene 7: Aiko, a frightened child, seeks your help and offers a gift." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Small charm (+2 ATK)" << endl;
    cout << "2. Mid: Family heirloom (+1 ATK, +1 DEF, -1 HP)" << endl;
    cout << "3. Risky: Desperate gift (+8 ATK, +3 DEF, -5 HP)" << endl;

    int choice7;
    cin >> choice7;

    if (choice7 == 1) {
        playerAtk += 2;
        cout << "You receive +2 ATK." << endl;
    } else if (choice7 == 2) {
        playerAtk += 1;
        playerDef += 1;
        playerHp -= 1;
        cout << "You receive +1 ATK, +1 DEF, -1 HP." << endl;
    } else if (choice7 == 3) {
        playerAtk += 8;
        playerDef += 3;
        playerHp -= 5;
        cout << "You receive +8 ATK, +3 DEF, -5 HP." << endl;
    } else {
        playerAtk += 2;
        cout << "Invalid choice. You receive +2 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 8: Master Renga
    cout << "Scene 8: Master Renga, a wise fighter, tests your resolve." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Basic training (+5 ATK)" << endl;
    cout << "2. Mid: Intense drill (+7 ATK, -2 HP)" << endl;
    cout << "3. Risky: Secret technique (gain Sunglasses, +2 DEF, -5 HP)" << endl;

    int choice8;
    cin >> choice8;

    if (choice8 == 1) {
        playerAtk += 5;
        cout << "You receive +5 ATK." << endl;
    } else if (choice8 == 2) {
        playerAtk += 7;
        playerHp -= 2;
        cout << "You receive +7 ATK, -2 HP." << endl;
    } else if (choice8 == 3) {
        hasSunglasses = true;
        playerDef += 2;
        playerHp -= 5;
        cout << "You gain Sunglasses, +2 DEF, -5 HP." << endl;
    } else {
        playerAtk += 5;
        cout << "Invalid choice. You receive +5 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 9: Mika
    cout << "Scene 9: Mika sells mystical charms." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Weak charm (+2 ATK)" << endl;
    cout << "2. Mid: Schala’s Amulet (survive 1 lethal blow, -3 HP)" << endl;
    cout << "3. Risky: Powerful charm (+11 ATK, +2 DEF, -7 HP)" << endl;

    int choice9;
    cin >> choice9;

    if (choice9 == 1) {
        playerAtk += 2;
        cout << "You receive +2 ATK." << endl;
    } else if (choice9 == 2) {
        hasAmulet = true;
        playerHp -= 3;
        cout << "You gain Schala’s Amulet, -3 HP." << endl;
    } else if (choice9 == 3) {
        playerAtk += 11;
        playerDef += 2;
        playerHp -= 7;
        cout << "You receive +11 ATK, +2 DEF, -7 HP." << endl;
    } else {
        playerAtk += 2;
        cout << "Invalid choice. You receive +2 ATK (safe option)." << endl;
    }
    cout << endl;

    // Scene 10: Supply Cache
    cout << "Scene 10: You find a hidden supply cache." << endl;
    cout << "Choose:" << endl;
    cout << "1. Safe: Healing supplies (set HP to 50)" << endl;
    cout << "2. Mid: Attack boosters (+12 ATK, -3 HP)" << endl;
    cout << "3. Risky: Ultimate cache (+23 ATK, +2 HP)" << endl;

    int choice10;
    cin >> choice10;

    if (choice10 == 1) {
        playerHp = 50;
        cout << "Your HP is restored to 50." << endl;
    } else if (choice10 == 2) {
        playerAtk += 12;
        playerHp -= 3;
        cout << "You receive +12 ATK, -3 HP." << endl;
    } else if (choice10 == 3) {
        playerAtk += 23;
        playerHp += 2;
        cout << "You receive +23 ATK, +2 HP." << endl;
    } else {
        playerHp = 50;
        cout << "Invalid choice. Your HP is restored to 50 (safe option)." << endl;
    }

    cout << endl;

    // Apply Rustbite
    if (hasRustbite) {
        bossDef -= 6;
        cout << "You activate Rustbite, reducing Bjorne's DEF by 6!" << endl;
    }

    // --- BOSS FIGHT START ---

    cout << endl << "Scene 11: Boss Fight - You confront Bjorne the Rogue Hollow!" << endl;
    cout << "Bjorne - HP: 400, ATK: 21, DEF: " << bossDef << endl << endl;

    // TURN 1
    if (playerHp > 0 && bossHp > 0) {
        cout << "Turn 1:" << endl;
        cout << "Jun - HP: " << playerHp << ", ATK: " << playerAtk << ", DEF: " << playerDef << endl;
        cout << "Bjorne - HP: " << bossHp << ", DEF: " << bossDef << endl;

        string taunt;
        if (bossHp > 300) taunt = "Tiny spark. I will crush you slowly.";
        else if (bossHp > 200) taunt = "You sting… nothing more.";
        else if (bossHp > 100) taunt = "Impossible… you persist?!";
        else taunt = "I will DEVOUR YOU!";

        cout << "Bjorne: " << taunt << endl;
        cout << "Choose your action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Divine Rapier (if available)" << endl;
        cout << "3. Dodge next attack (if Net or Sunglasses available)" << endl;

        int action1;
        cin >> action1;

        bool dodged1 = false;

        if (action1 == 2) {
            if (hasRapier) {
                bossHp -= 275;
                hasRapier = false;
                cout << "You strike with Divine Rapier! 275 true damage!" << endl;
            } else {
                int damage = max(1, playerAtk - bossDef);
                bossHp -= damage;
                cout << "No Rapier available. You attack! Dealt " << damage << " damage." << endl;
            }
        } else if (action1 == 3) {
            if (hasNet || hasSunglasses) {
                dodged1 = true;
                if (hasNet) {
                    hasNet = false;
                    cout << "You deploy the Net! You dodge the next attack." << endl;
                } else {
                    hasSunglasses = false;
                    cout << "You use the Sunglasses! You dodge the next attack." << endl;
                }
            } else {
                int damage = max(1, playerAtk - bossDef);
                bossHp -= damage;
                cout << "No dodge available. You attack! Dealt " << damage << " damage." << endl;
            }
        } else {
            int damage = max(1, playerAtk - bossDef);
            bossHp -= damage;
            cout << "You attack! Dealt " << damage << " damage." << endl;
        }

        if (bossHp <= 0) {
            cout << "You have defeated Bjorne!" << endl;
            cout << "The shinigami arrive and see your courage. You are recruited into the Academy." << endl;
            cout << "Victory Ending!" << endl;
        } else {
            if (!dodged1) {
                int damage = max(1, bossAtk - playerDef);
                playerHp -= damage;
                cout << "Bjorne attacks! You take " << damage << " damage." << endl;
            } else {
                cout << "You successfully dodge Bjorne's attack!" << endl;
            }

            if (playerHp <= 0 && hasAmulet) {
                playerHp = 1;
                hasAmulet = false;
                cout << "Schala's Amulet shatters, restoring you to 1 HP!" << endl;
            }

            if (playerHp <= 0) {
                cout << "Bjorne defeats you..." << endl;
                cout << "The shinigami arrive too late but finish the Hollow. You are remembered as a hero in District 67." << endl;
                cout << "Defeat Ending!" << endl;
            }
        }
    }

    // TURN 2
    if (playerHp > 0 && bossHp > 0) {
        cout << "Turn 2:" << endl;
        cout << "Jun - HP: " << playerHp << ", ATK: " << playerAtk << ", DEF: " << playerDef << endl;
        cout << "Bjorne - HP: " << bossHp << ", DEF: " << bossDef << endl;

        string taunt;
        if (bossHp > 300) taunt = "Tiny spark. I will crush you slowly.";
        else if (bossHp > 200) taunt = "You sting… nothing more.";
        else if (bossHp > 100) taunt = "Impossible… you persist?!";
        else taunt = "I will DEVOUR YOU!";

        cout << "Bjorne: " << taunt << endl;
        cout << "Choose your action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Divine Rapier (if available)" << endl;
        cout << "3. Dodge next attack (if Net or Sunglasses available)" << endl;

        int action2;
        cin >> action2;

        bool dodged2 = false;

        if (action2 == 2) {
            if (hasRapier) {
                bossHp -= 275;
                hasRapier = false;
                cout << "You strike with Divine Rapier! 275 true damage!" << endl;
            } else {
                int damage = max(1, playerAtk - bossDef);
                bossHp -= damage;
                cout << "No Rapier available. You attack! Dealt " << damage << " damage." << endl;
            }
        } else if (action2 == 3) {
            if (hasNet || hasSunglasses) {
                dodged2 = true;
                if (hasNet) {
                    hasNet = false;
                    cout << "You deploy the Net! You dodge the next attack." << endl;
                } else {
                    hasSunglasses = false;
                    cout << "You use the Sunglasses! You dodge the next attack." << endl;
                }
            } else {
                int damage = max(1, playerAtk - bossDef);
                bossHp -= damage;
                cout << "No dodge available. You attack! Dealt " << damage << " damage." << endl;
            }
        } else {
            int damage = max(1, playerAtk - bossDef);
            bossHp -= damage;
            cout << "You attack! Dealt " << damage << " damage." << endl;
        }

        if (bossHp <= 0) {
            cout << "You have defeated Bjorne!" << endl;
            cout << "The shinigami arrive and see your courage. You are recruited into the Academy." << endl;
            cout << "Victory Ending!" << endl;
        } else {
            if (!dodged2) {
                int damage = max(1, bossAtk - playerDef);
                playerHp -= damage;
                cout << "Bjorne attacks! You take " << damage << " damage." << endl;
            } else {
                cout << "You successfully dodge Bjorne's attack!" << endl;
            }

            if (playerHp <= 0 && hasAmulet) {
                playerHp = 1;
                hasAmulet = false;
                cout << "Schala's Amulet shatters, restoring you to 1 HP!" << endl;
            }

            if (playerHp <= 0) {
                cout << "Bjorne defeats you..." << endl;
                cout << "The shinigami arrive too late but finish the Hollow. You are remembered as a hero in District 67." << endl;
                cout << "Defeat Ending!" << endl;
            }
        }
    }

    return 0;
}

