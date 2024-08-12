pipeline {
    agent any
    stages {
        stage('Checkout Main') {
            steps {
                // Checkout the main branch
                git branch: 'main', url: 'https://github.com/your-repo-url.git'
            }
        }
        stage('Checkout Code') {
            steps {
                // Checkout the code branch
                script {
                    sh 'git fetch origin code:code'
                    sh 'git checkout code'
                }
            }
        }
        stage('Checkout Test') {
            steps {
                // Checkout the Test branch
                script {
                    sh 'git fetch origin Test:Test'
                    sh 'git checkout Test'
                }
            }
        }
        stage('---clean---') {
            steps {
                sh "mvn clean"
            }
        }
        stage('--build--') {
            steps {
                sh """
                mkdir -p build
                cd build
                cmake ..
                make
                """
            }
        }
        stage('--test--') {
            steps {
                sh """
                cd build
                ./runTests --gtest_output=xml:test_results.xml
                """
            }
        }
        stage('--package--') {
            steps {
                sh "mvn package"
            }
        }
    }
    post {
        always {
            junit 'build/test_results.xml'
        }
    }
}

