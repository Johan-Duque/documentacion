# OMKA - Product Catalog and Corporate Site

This project is a modern corporate website developed with Next.js, React, and TypeScript, designed to serve as a product catalog, blog, and information hub for the OMKA company.

## Tech Stack

- **Framework:** [Next.js](https://nextjs.org/) (with App Router)
- **Language:** [TypeScript](https://www.typescriptlang.org/)
- **UI:** [React](https://reactjs.org/)
- **Styling:** [Tailwind CSS](https://tailwindcss.com/)
- **Data Management:** Local JSON files as a content system (Headless CMS).
- **Maps:** [Leaflet.js](https://leafletjs.com/) for distributor visualization.
- **Images:** Hosted on [Cloudinary](https://cloudinary.com/).

## Project Architecture

The application uses a "Git-based CMS" approach, where all content (products, blog posts, clients) is stored in JSON files within the `data/jsons/` directory.

- **`src/app/`**: Contains the route structure and pages of the application, using the Next.js App Router. The folders here map directly to the site's URLs.
- **`data/jsons/`**: Acts as the project's "database". Server components read these files to get the data to be displayed.
- **`src/libs/serverData.tsx`**: A key component that exports the `getLocalData` function. This utility runs exclusively on the server (thanks to the `server-only` package) to read and parse JSON files from the file system.
- **`next.config.ts`**: Next.js configuration, which includes the remote image domain configuration for Cloudinary.

## Getting Started

To run this project in a local development environment, follow these steps:

1.  **Clone the repository**
    ```bash
    git clone <REPOSITORY_URL>
    cd OMKA
    ```

2.  **Install dependencies**
    `npm` is used as the package manager.
    ```bash
    npm install
    ```

3.  **Run the development server**
    ```bash
    npm run dev
    ```
    Open [http://localhost:3000](http://localhost:3000) in your browser to see the result.

## Available Scripts

In the `package.json` file, you will find the following scripts:

- **`npm run dev`**: Starts the application in development mode.
- **`npm run build`**: Compiles the application for production.
- **`npm run start`**: Starts a production server with the compiled version.
- **`npm run lint`**: Runs ESLint to analyze the code for issues.

## External Data Sources

This project depends on an external service for image hosting:

- **Cloudinary**: All product and content images are served from Cloudinary. The configuration is in `next.config.ts`. Full functionality would require access to the corresponding Cloudinary account.
