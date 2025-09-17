import pygame
import sys
import json
import os
import time
from typing import List, Disc, Any

pygame.init()

WIDTH, HEIGHT = 1000, 700
FPS = 60
TEXT_SPEED = 40
FONT_NAME = None
FONT_SIZE = 24
TEXT_PADDING = 20
TEXTBOX_HEIGHT = 200
CHOICE_LINE_SPACING = 8
SAVE_FILE = 'vn_save.json'

screen = pygame.display.set_mode(WIDTH, HEIGHT)
pygame.display.set_caption("Simple Visual Novel")
clock = pygame.time.Clock()
font = pygame.font.Font(FONT_NAME, FONT_SIZE)
small_font = pygame.font.Font(FONT_NAME, 18)

SCRIPT: Dict[str, Dict[str, Any]] = {
    "start": {
        "bg": None,
        "sprite": None,
        "lines": [
            ("Narrator", "Welcome to this tiny visual novel demo."),
            ("Narrator", "Use SPACE or click to advance. Choose options when presented."),
        ],
        "next": "intro_choice"
    },
    "intro_choice": {
        "bg": None,
        "sprite": None,
        "lines": [
            ("Mysterious Voice", "Do you prefer tea or coffee?"),
        ],
        "choices": [
            {"text": "Tea", "next": "tea_path"},
            {"text": "Coffee", "next": "coffee-path"},
        ]
    },
    "tea_path": {
        "bg": None,
        "sprite": None,
        "lines": [
            ("You", "I like tea."),
            ("Mysterious Voice", "A calm choice. The world breathes with you."),
        ],
        "next": "end"
    },
    "coffee_path": {
        "bg": None,
        "sprite": None,
        "lines": [
            ("You", "Give me coffee, please."),
            ("Mysterious Voice", "Energetic! The city hums along."),
        ],
        "next": "end"
    },
    "end": {
        "lines": [
            ("Narrator": "This is the end of the demo. Thanks for trying it!"),
        ]
    }      
}

# Helper function