# Portfolio

This is a personal portfolio website showcasing my skills, projects, and experience as a Front-end Developer. The website is built with modern web technologies to provide a responsive and engaging user experience.

## Features

-   **Component-Based Architecture:** Built with React, the UI is divided into reusable and modular components.
-   **TypeScript:** The project is written in TypeScript, providing static typing for better code quality and maintainability.
-   **Styling:** Uses CSS Modules for scoped styling of components, and global styles for the overall theme.
-   **Multilingual Support:** The website supports both English and Spanish, with translations managed through a custom React Context.
-   **Data from JSON:** The content for the About, Experience, Projects, and Technologies sections is fetched from local JSON files, making it easy to update.
-   **Lazy Loading:** Sections are loaded lazily to improve the initial loading time.
-   **Vite:** A fast build tool provides a lightning-fast development experience.

## Technologies Used

-   **React:** A JavaScript library for building user interfaces.
-   **TypeScript:** A typed superset of JavaScript that compiles to plain JavaScript.
-   **Vite:** A fast build tool that provides a lightning-fast development experience.
-   **HTML5 & CSS3:** The standard markup and styling languages for creating web pages.

## Libraries Used

-   `react`: Core React library.
-   `react-dom`: React package for working with the DOM.
-   `react-icons`: A collection of popular SVG icons as React components.

## Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

-   npm
    ```sh
    npm install npm@latest -g
    ```

### Installation

1.  Clone the repo
    ```sh
    git clone https://github.com/your_username_/Project-Name.git
    ```
2.  Install NPM packages
    ```sh
    npm install
    ```
3.  Run the development server
    ```sh
    npm run dev
    ```

## Application Structure

The project follows a component-based architecture, organizing the codebase into reusable and modular pieces.

```
Portfolio/
├── public/                 # Static assets (images, favicon)
├── src/                    # Main application source code
│   ├── App.tsx             # Main application component
│   ├── index.css           # Global styles
│   ├── main.tsx            # Entry point of the application
│   ├── Components/         # Reusable UI components
│   │   ├── Carousel/
│   │   ├── Error/
│   │   ├── Hero/
│   │   ├── Loading/
│   │   ├── Navigation/
│   │   └── ProjectCard/
│   ├── Contexts/           # React Contexts for global state management
│   │   └── LanguageContext.tsx
│   ├── Hooks/              # Custom React Hooks for reusable logic
│   │   └── index.ts
│   ├── jsons/              # JSON files with the application data
│   │   ├── about.json
│   │   ├── experience.json
│   │   ├── projects.json
│   │   └── technologies.json
│   ├── libs/               # Utility functions
│   │   └── index.ts
│   └── Sections/           # Major sections of the portfolio
│       ├── About/
│       ├── Experience/
│       ├── Footer/
│       ├── Home/
│       ├── Projects/
│       └── Technologies/
├── .gitignore              # Specifies intentionally untracked files to ignore
├── index.html              # Main HTML file
├── package.json            # Project metadata and dependencies
└── vite.config.ts          # Vite configuration
```