Can you reverse the AES encryption with a specially crafted plaintext (maybe TB in size?)?

Do ransomeware algorithms reuse the key? How do they keep track of the key? If the key is derived from the machine, then the code of the algorithm would reveal the key.

If it is independent of the machine, but different for each machine, then the key must be stored either on the machine (in which case the code should reveal the location), or remotely, in which case network analysis might yield insights to the origin of the attack. 

If the same key is used, watching an encryption occur in realtime will yield the key (as it will be stored in memory). The ransomeware could be purposefully infected on a new machine for this purpose. 

For the decryption to occur, the machine must be able to receive remote instructions. How do attackers continue to maintain remote communication securely? 

Social engineering: what if you staged an attack on a high-profile company. The event is widely publicised. The company eventually pays the ransome, but the attacker is unable to decrypt the files. Everyone in the world hears about this and the message is clear: "don't pay the ransome because they can't reverse the problem." Now, no one will believe any attacker. Proof of the ability to reverse the encryption will be required before payment is issued. This creates a dialogue between the attacker and the victim (which at this point includes the NSA, FBI, etc...). 

